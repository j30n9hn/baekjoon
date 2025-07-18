/*
 * Description: Dynamic Programming (Bottom-Up), Math (Recurrence relation)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* dpArr;
} memo;

void initMemo(memo* m, int size);
void freeMemo(memo* m);
int dp(memo* m, int value);

int main() {
    int value;
    int numberOfTestCases;
    memo m;

    scanf("%d", &numberOfTestCases);

    for (int i = 0; i < numberOfTestCases; i++) {
        scanf("%d", &value);
        initMemo(&m, value);
        printf("%d\n", dp(&m, value));
        freeMemo(&m);
    }

    return 0;
}

void initMemo(memo* m, int size) {
    m->dpArr = (int*)malloc(sizeof(int) * (size + 1));
    m->dpArr[1] = 1;
    m->dpArr[2] = 2;
    m->dpArr[3] = 4;
}

void freeMemo(memo* m) {
    free(m->dpArr);
    m->dpArr = NULL;
}

int dp(memo* m, int value) {
    for (int i = 4; i <= value; i++) {
        m->dpArr[i] = m->dpArr[i - 1] + m->dpArr[i - 2] + m->dpArr[i - 3];
    }

    return m->dpArr[value];
}