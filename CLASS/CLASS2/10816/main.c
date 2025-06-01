/*
* Description: Binary search
*/
#include<stdio.h>
#include<stdlib.h>

int compare( const void* arg1, const void* arg2);
int binarySearchStart(int num, int start, int end, int db[]);
int binarySearchEnd(int num, int start, int end, int db[]);

int main() {
    int deckCnt;
    int checkCnt;
    int checkNum;
    int start;
    int end;
    int result;
    int* deckArr;

    scanf("%d", &deckCnt);
    deckArr = (int*)malloc(sizeof(int) * deckCnt);
    
    for (int i = 0; i < deckCnt; i++) {
        scanf("%d", &deckArr[i]);
    }
    qsort(deckArr, deckCnt, sizeof(int), compare);

    scanf("%d", &checkCnt);
    for (int i = 0; i < checkCnt; i++) {
        scanf("%d", &checkNum);
        start = binarySearchStart(checkNum, 0, deckCnt, deckArr);
        end = binarySearchEnd(checkNum, start, deckCnt, deckArr);
        result = end - start;
        printf("%d ", result);
    }

    free(deckArr);
    deckArr = NULL;
    return 0;
}

int compare( const void* arg1, const void* arg2) {
    int argOne = *(int*)arg1;
    int argTwo = *(int*)arg2;
    if ( argOne > argTwo ) return 1;
    else if ( argOne < argTwo ) return -1;
    else return 0;
}

int binarySearchStart(int num, int start, int end, int db[]) {
    int mid;
    int result = -1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (num <= db[mid]) {
            if (num == db[mid]) result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result == - 1 ? 0 : result - 1;
}

int binarySearchEnd(int num, int start, int end, int db[]) {
    int mid;
    int result = -1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (num >= db[mid]) {
            if (num == db[mid]) result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result == -1 ? 0 : result;
}