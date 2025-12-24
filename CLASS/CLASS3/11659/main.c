/*
 * Description: Calculate range sums of an integer array efficiently
 * Approach: Cumulative sum array, prefix sum
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    unsigned long long sum;
} prefixSumArr;

int main() {
    int amount, numQueries;
    int start, end;

    scanf("%d %d", &amount, &numQueries);

    prefixSumArr* prefixSum = (prefixSumArr*)calloc(amount, sizeof(prefixSumArr));

    for (int i = 0; i < amount; i++) {
        scanf("%d", &prefixSum[i].number);
        if (i == 0) prefixSum[i].sum = prefixSum[i].number;
        else prefixSum[i].sum = prefixSum[i].number + prefixSum[i - 1].sum;
    }

    for (int i = 0; i < numQueries; i++) {
        scanf("%d %d", &start, &end);
        unsigned long long result;
        if (start == 1)
            result = prefixSum[end - 1].sum;
        else
            result = prefixSum[end - 1].sum - prefixSum[start - 2].sum;

        printf("%llu\n", result);
    }

    free(prefixSum);
    return 0;
}

