#include<stdio.h>
#include<stdlib.h>

int compare( const void* arg1, const void* arg2 );
int binarySearch( int num, int start, int end, int db[] );

int main() {
    int dbcnt, numcnt;
    int result;
    int index;
    int num;
    int* db;

    scanf("%d", &dbcnt);
    db = (int*)malloc(sizeof(int) * dbcnt);
    for (int i = 0; i < dbcnt; i++) {
        scanf("%d", &db[i]);
    }

    qsort(db, dbcnt, sizeof(int), compare);

    scanf("%d", &numcnt);
    for (int i = 0; i < numcnt; i++) {
        scanf("%d", &num);
        result = binarySearch(num, 0, dbcnt - 1, db);
        printf("%d\n", result);
    }


    free(db);
    db = NULL;
    return 0;
}

int compare( const void* arg1, const void* arg2 ) {
    int a = *(int*)arg1;
    int b = *(int*)arg2;
    if (a < b) return 1;
    else if (a > b) return -1;
    else return 0;
}

int binarySearch( int num, int start, int end, int db[] ) {
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (num == db[mid]) {
            return 1;
        } else if (num > db[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}