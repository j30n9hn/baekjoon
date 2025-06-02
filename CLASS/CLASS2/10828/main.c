/*
 * Description: Fixed Sized Stack
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int top;
    int capacity;
    int* stackArray;
} stack;

void initStack(int capacity, stack* s);
void freeStack(stack* s);
int push(int value, stack* s);
int pop(stack* s);
int peek(stack* s);
int isEmpty(stack* s);

int main() {
    int value;
    int capacity;
    int cnt;
    char cmd[6];
    stack s;

    scanf("%d", &cnt);
    initStack(cnt, &s);

    for (int i = 0; i < cnt; i++) {
        scanf("%s", cmd);
        if (strstr(cmd, "push") != NULL) {
            scanf("%d", &value);
            push(value, &s);
        } else if (strstr(cmd, "pop") != NULL) {
            printf("%d\n", pop(&s));
        } else if (strstr(cmd, "size") != NULL) {
            printf("%d\n", s.top + 1);
        } else if (strstr(cmd, "empty") != NULL) {
            printf("%d\n", isEmpty(&s));
        } else {
            printf("%d\n", peek(&s));
        }
    }

    freeStack(&s);
    return 0;
}

void initStack(int capacity, stack* s) {
    s->capacity = capacity;
    s->stackArray = (int*)malloc(sizeof(int) * capacity);
    for (int i = 0; i < capacity; i++) {
        s->stackArray[i] = 0;
    }
    s->top = -1;
}

void freeStack(stack* s) {
    free(s->stackArray);
    s->stackArray = NULL;
}

int push(int value, stack* s) {
    if (s->top >= s->capacity - 1) return -1;
    s->stackArray[++s->top] = value;
    return 0;
}

int pop(stack* s) {
    if (s->top < 0) return -1;
    return s->stackArray[s->top--];
}

int peek(stack* s) {
    if (s->top < 0) return -1;
    return s->stackArray[s->top];
}

int isEmpty(stack* s) {
    if (s->top < 0) return 1;
    else return 0;
}