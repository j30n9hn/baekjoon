#include<stdio.h>
#include<stdlib.h>

int compare( const void* arg1, const void* arg2);

int main() {
    int cnt;
    int* num;

    scanf("%d", &cnt);

    num = (int*)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num[i]);
    }

    qsort(num, cnt, sizeof(int), compare);

    for (int i = 0; i < cnt; i++) {
        printf("%d\n", num[i]);
    }    

    free(num);
    num = NULL;

    return 0;
}

int compare( const void* arg1, const void* arg2) {
    return (*(int*)arg1 - *(int*)arg2);
}