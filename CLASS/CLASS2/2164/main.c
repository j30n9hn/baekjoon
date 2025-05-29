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
int getFront(queueValue* q);
void enqueue(int value, queueValue* q);
int dequeue(queueValue* q);

int main() {
    int num;
    int temp = 0;
    queueValue q;

    scanf("%d", &num);
    
    initValue(num, &q);
    for (int i = 1; i <= num; i++) {
        enqueue(i, &q);
    }
    
    while (q.size > 1) {
        dequeue(&q);
        temp = dequeue(&q);
        enqueue(temp, &q);
    }

    printf("%d\n", getFront(&q));

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

int getFront(queueValue* q) {
    return q->arr[q->front];
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
        q->arr[q->front] = 0;
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
    return front;
}