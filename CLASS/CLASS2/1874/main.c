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
int peek(stack* s);

int main() {
    char arr[200000];
    int failFlag = 0;
    int cnt;
    int index = 0;
    int arrIndex = 0;
    int* num;
    stack s;

    scanf("%d", &cnt);
    num = (int*)malloc(sizeof(int) * cnt);
    initStack(cnt, &s);

    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num[i]);
    }
    
    for (int i = 1; i <= cnt; i++) {;
        if ( peek(&s) == num[index]) {
            while (peek(&s) == num[index]) {
                pop(&s);
                index++;
                arr[arrIndex] = '-';
                arrIndex++;
            }
        }
        push(i, &s);
        arr[arrIndex] = '+';
        arrIndex++;
        if (peek(&s) > num[index]) {
            failFlag = 1;
            break; 
        }
    }

    while (isEmpty(&s) != 1) {
        if (peek(&s) > num[index]) {
            failFlag = 1;
            break; 
        }
        pop(&s);
        index++;
        arr[arrIndex] = '-';
        arrIndex++;
    }

    if (failFlag != 1) {
        for (int i = 0; i < arrIndex; i++) {
            printf("%c\n", arr[i]);
        }   
    } else {
        printf("NO\n");
    }
    freeStack(&s);
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

int peek(stack* s) {
    if (s->top < 0) return -1;
    return s->stackArray[s->top];
} 