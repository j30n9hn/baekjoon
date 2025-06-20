/*
 * Description: Quick sort
 */

#include<stdio.h>
#include<stdlib.h>

int compare(const void* arg1, const void* arg2);

int main() {
    int size;
    int** coordinate;

    scanf("%d", &size);

    coordinate = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        coordinate[i] = (int*)malloc(sizeof(int) * 2);
    }

    for (int i = 0; i < size; i++) {
        scanf("%d %d", &coordinate[i][0], &coordinate[i][1]);
    }

    qsort(coordinate, size, sizeof(int*), compare);

    for (int i = 0; i < size; i++) {
        printf("%d %d\n", coordinate[i][0], coordinate[i][1]);
    }

    for (int i = 0; i < size; i++) {
        free(coordinate[i]);
        coordinate[i] = NULL;
    }
    free(coordinate);
    coordinate = NULL;

    return 0;
}

int compare(const void* arg1, const void* arg2) {
    const int* num1 = *(const int**)arg1;
    const int* num2 = *(const int**)arg2;

    if (num1[1] != num2[1]) {
        if (num1[1] < num2[1]) return -1;
        else if (num1[1] > num2[1]) return 1;
        else return 0;
    } else {
        if (num1[0] < num2[0]) return -1;
        else if (num1[0] > num2[0]) return 1;
        else return 0;
    }
}