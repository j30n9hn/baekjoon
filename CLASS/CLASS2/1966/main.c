/*
 * Description: Circular queue 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
int compare(const void* arg1, const void* arg2);

int main() {
    int loop;
    int size;
    int result;
    int position;
    int num;
    int* priority;
    int index = 0;
    int cnt = 0;
    queueValue q;

    scanf("%d", &loop);

    for (int k = 0; k < loop; k++) {
        scanf("%d %d", &size, &position);
    
        priority = (int*)malloc(sizeof(int) * size);
        initValue(size, &q);

        for (int i = 0; i < size; i++) {
            scanf("%d", &num);
            if (i == position) enqueue(num * -1, &q);
            else enqueue(num, &q);
            priority[i] = num;
        }

        qsort(priority, size, sizeof(int), compare);

        while (1) {
            if (getFront(&q) * -1 == priority[index]) {
                    printf("%d\n", cnt + 1);
                    break;
                }
            if (getFront(&q) != priority[index]) {
                result = dequeue(&q);
                if (result == 10) break;
                enqueue(result, &q);
            } else {
                if (dequeue(&q) == 10) break;
                index++;
                cnt++;
            }
        }

        cnt = 0;
        index = 0;
        free(priority);
        priority = NULL;
        freeValue(&q);
    }
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
        printf("Queue is full\n");
        return;
    } else {
        rear = (q->front + q->size) % q->capacity;
        q->arr[rear] = value;
        q->size++;
    }
}

int dequeue(queueValue* q) {
    int del;
    if (q->size == 0) {
        printf("Queue is empty\n");
        return 10;
    } else {
        del = q->arr[q->front];
        q->arr[q->front] = 0;
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
    return del;
}

int compare(const void* arg1, const void* arg2) {
    int num1 = *(const int*)arg1;
    int num2 = *(const int*)arg2;
    if (num1 < num2) return 1;
    else if (num1 > num2) return -1;
    else return 0;
}