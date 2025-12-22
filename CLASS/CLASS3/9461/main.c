/*
 * Description: Padovan sequence using dynamic programming (top-down with memoization)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned long long* arr;
} padovanArray;

void initPadovan(padovanArray* padovan);
void freePadovan(padovanArray* padovan);
unsigned long long padovanSequence(padovanArray* padovan, int index);

int main() {
    int testCase;
    int loop;
    int index;
    unsigned long long value = 0;
    padovanArray padovan;
    scanf("%d", &testCase);

    for (loop = 0; loop < testCase; loop++) {
        initPadovan(&padovan);
        scanf("%d", &index);
        value = padovanSequence(&padovan, index);
        printf("%llu\n", value);
        freePadovan(&padovan);
    }
    
    return 0;
}


void initPadovan(padovanArray* padovan) {
    padovan->arr = (unsigned long long*)calloc(101, sizeof(unsigned long long));
    padovan->arr[1] = 1;
    padovan->arr[2] = 1;
    padovan->arr[3] = 1;
    padovan->arr[4] = 2;
    padovan->arr[5] = 2;
    padovan->arr[6] = 3;
    padovan->arr[7] = 4;
    padovan->arr[8] = 5;
    padovan->arr[9] = 7;
    padovan->arr[10] = 9;
} 

void freePadovan(padovanArray* padovan) {
    free(padovan->arr);
    padovan->arr = NULL;
}

unsigned long long padovanSequence(padovanArray* padovan, int index) {
    if (index <= 0) return 0;
    if (padovan->arr[index] != 0) return padovan->arr[index];
    
    padovan->arr[index] = padovanSequence(padovan, index - 1) + padovanSequence(padovan, index - 5);
    return padovan->arr[index];
}
