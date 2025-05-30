/*
* Description: Queue (Circular)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int front;
    int size;
    int capacity;
    int* queueArr;
} queue;

void initQueue(int num, queue* q);
void freeQueue(queue* q);
void enqueue(int value, queue* q);
int dequeue(queue* q);
int getFront(queue* q);
int getRear(queue* q);
int isEmpty(queue* q);

int main() {
    char cmd[6];
    char* findStr;
    int num;
    int value;
    queue q;

    initQueue(10000, &q);
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%5s", cmd);

        if (strstr(cmd, "push") != NULL) {
            scanf("%d", &value);
            enqueue(value, &q);
        } else if (strstr(cmd, "pop") != NULL) {
            printf("%d\n", dequeue(&q));
        } else if (strstr(cmd, "size") != NULL) {
            printf("%d\n", q.size);
        } else if (strstr(cmd, "empty") != NULL) {
            printf("%d\n", isEmpty(&q));
        } else if (strstr(cmd, "front") != NULL) {
            printf("%d\n", getFront(&q));
        } else {
            printf("%d\n", getRear(&q));
        } 
    }

    freeQueue(&q);
    return 0;
}

void initQueue(int num, queue* q) {
    q->front = 0;
    q->size = 0;
    q->capacity = num;
    q->queueArr = (int*)malloc(sizeof(int) * num);
}

void freeQueue(queue* q) {
    free(q->queueArr);
    q->queueArr = NULL;
}

// push X
void enqueue(int value, queue* q) {
    int rear;
    if (q->size == q->capacity) {
        return;
    } else {
        rear = (q->front + q->size) % q->capacity;
        q->queueArr[rear] = value;
        q->size++;
    }
}

// pop
int dequeue(queue* q) {
    int front;
    if (q->size == 0) {
        return -1;
    } else {
        front = q->queueArr[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
    return front;
}

// front
int getFront(queue* q) {
    if (q->size == 0) {
        return -1;
    } else {
        return q->queueArr[q->front];
    }
}

// back
int getRear(queue* q) {
    if (q->size == 0) {
        return -1;
    } else {
        return q->queueArr[(q->front + q->size - 1) % q->capacity];
    }
}

int isEmpty(queue* q) {
    if (q->size == 0) {
        return 1;
    } else {
        return 0;
    }
}