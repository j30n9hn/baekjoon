#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int size;
    int capacity;
    int front;
    int* arr;
} queueValue;

void initValue(int num, queueValue* q);
void freeValue(queueValue* q);
void enqueue(int value, queueValue* q);
int dequeue(queueValue* q);

int main() {
    int num;
    int position;
    int deleted;
    queueValue q;

    scanf("%d %d", &num, &position);
    
    initValue(num, &q);
    for (int i = 1; i <= num; i++) {
        enqueue(i, &q);
    }

    printf("<");
    for (int k = 0; k < num; k++) {
        q.size--;
        if (q.size == 0) break;
        for (int i = 0; i < position - 1; i++) {
            dequeue(&q);
            while (q.arr[q.front] == 0) {
                dequeue(&q);
            }
        }
        deleted = q.arr[q.front];
        q.arr[q.front] = 0;
        printf("%d", deleted);
        while (q.arr[q.front] == 0) {
            dequeue(&q);
        }
        printf(", ");
    }
    printf("%d", q.arr[q.front]);
    printf(">");

    freeValue(&q);

    return 0;
}

void initValue(int num, queueValue* q) {
    q->size = 0;
    q->capacity = num;
    q->front = 0;
    q->arr = (int*)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++) {
        q->arr[i] = 0;
    }
}

void freeValue(queueValue* q) {
    free(q->arr);
    q->arr = NULL;
}

void enqueue(int value, queueValue* q) {
    int rear;
    if (q->size == q->capacity) {
        return;
    } else {
        rear = (q->front + q->size) % q->capacity;
        q->arr[rear] = value;
        q->size++;
    }   
}

int dequeue(queueValue* q) {
    int front;
    if (q->size == 0) {
        return -1;
    } else {
        front = q->arr[q->front];
        q->front = (q->front + 1) % q->capacity;
    }
    return front;
}