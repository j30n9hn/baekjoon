/**
 * Description: Quick sort
 */
#include <stdio.h>
#include <stdlib.h>

int compare(const void* arg1, const void* arg2);

int main() {
    int cnt;
    int present;
    int sum;
    int* time;

    scanf("%d", &cnt);

    time = (int*)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &time[i]);
    }

    qsort(time, cnt, sizeof(int), compare);

    present = 0;
    sum = 0;
    for (int i = 0; i < cnt; i++) {
        present += time[i];
        sum += present;
    }

    printf("%d\n", sum);

    free(time);
    time = NULL;
    return 0;
}

int compare(const void* arg1, const void* arg2) {
    const int num1 = *(const int*) arg1;
    const int num2 = *(const int*) arg2;
    
    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}