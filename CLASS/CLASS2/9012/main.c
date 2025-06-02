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
int isEmpty(stack* s);

int main() {
    int cnt;
    int underflowFlag;
    int len;
    char parenthesis[61];
    stack s;

    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++) {
        initStack(51, &s);
        underflowFlag = 0;
        scanf("%s", parenthesis);
        len = strlen(parenthesis);
        for (int j = 0; j < len; j++) {
            if (parenthesis[j] == '(') {
                push(1, &s);
            } else if (parenthesis[j] == ')') {
                if (isEmpty(&s) == 1) {
                    underflowFlag = 1;
                    break;
                }
                pop(&s);
            }
        }
        if ((isEmpty(&s) == 1) && underflowFlag == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        freeStack(&s);
    }

    return 0;
}

void initStack(int capacity, stack* s) {
    s->capacity = capacity;
    s->stackArray = (int*)calloc(capacity, sizeof(int));
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