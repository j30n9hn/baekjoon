/*
 * Description: Dynamic Programming (Bottom-Up)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* table;
} memo;

void initMemo(memo* memo, int num);
void freeMemo(memo* memo);
int getMinimum(memo* memo, int num);

int main() {
    int num;
    int result;
    memo memo;

    scanf("%d", &num);
    initMemo(&memo, num);
    
    result = getMinimum(&memo, num);
    printf("%d\n", result);

    freeMemo(&memo);
    return 0;
}

void initMemo(memo* memo, int num) {
    memo->table = (int*)malloc(sizeof(int) * (num + 1));
    memo->table[1] = 0;
}

void freeMemo(memo* memo) {
    free(memo->table);
    memo->table = NULL;
}

int getMinimum(memo* memo, int num) {
    for (int i = 2; i <= num; i++) {
        memo->table[i] = memo->table[i - 1] + 1;
        if (i % 3 == 0 && memo->table[i] > memo->table[i / 3] + 1) memo->table[i] = memo->table[i / 3] + 1;
        if (i % 2 == 0 && memo->table[i] > memo->table[i / 2] + 1) memo->table[i] = memo->table[i / 2] + 1;
    }
    return memo->table[num];
}