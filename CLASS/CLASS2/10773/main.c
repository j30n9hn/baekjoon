/*
 * Description: Fixed Sized Stack
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int top;
    int capacity;
    char* stackArray;
} stack;

void initStack(int capacity, stack* s);
void freeStack(stack* s);
int push(int value, stack* s);
int pop(stack* s);
int isEmpty(stack* s);

int main() {
    int cnt;
    int num;
    stack s;

    scanf("%d", &cnt);
    initStack(cnt, &s);
    
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num);
        if (num != 0) push(num, &s);
        else pop(&s);
    }

    num = 0;

    for (int i = 0; i < cnt; i++) {
        if (isEmpty(&s) == 1) break;
        num += pop(&s);
    }

    printf("%d\n", num);
    freeStack(&s);
    return 0;
}

void initStack(int capacity, stack* s) {
    s->capacity = capacity;
    s->stackArray = (char*)calloc(capacity, sizeof(char));
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

int isEmpty(stack* s) {
    if (s->top < 0) return 1;
    else return 0;
}