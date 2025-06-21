/*
 * Description: Fixed Sized Stack
 * if strcmp(input, ".") != 0:
 * scanf("%s", input);
 * stack(input); // Every lefts are push, every rights are pop. 
 * if (isEmpty() == 0) yes
 * else no
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
int push(char value, stack* s);
char pop(stack* s);
int isEmpty(stack* s);

int main() {
    char string[101];
    int underflowFlag;
    int len;
    stack s;

    while (1) {
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = 0;

        if (strcmp(string, ".") == 0) break;
        if (strlen(string) == 0) continue;

        initStack(101, &s);
        underflowFlag = 0;
        len = strlen(string);
        for (int i = 0; i < len; i++) {
            if (string[i] == '(') {
                push('(', &s);
            } else if (string[i] == '[') {
                push('[', &s);
            } else if (string[i] == ')') {
                if (isEmpty(&s) == 1) {
                    underflowFlag = 1;
                    break;
                }
                if (pop(&s) != '(') {
                    underflowFlag = 1;
                    break;
                }
            } else if (string[i] == ']') {
                if (isEmpty(&s) == 1) {
                    underflowFlag = 1;
                    break;
                }
                if (pop(&s) != '[') {
                    underflowFlag = 1;
                    break;
                }
            } else {
                continue;
            }
        }
        if ((isEmpty(&s) == 1) && underflowFlag == 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
        freeStack(&s);
    }

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

int push(char value, stack* s) {
    if (s->top >= s->capacity - 1) return -1;
    s->stackArray[++s->top] = value;
    return 0;
}

char pop(stack* s) {
    if (s->top < 0) return -1;
    return s->stackArray[s->top--];
}

int isEmpty(stack* s) {
    if (s->top < 0) return 1;
    else return 0;
}