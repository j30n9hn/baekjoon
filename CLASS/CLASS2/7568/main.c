/*
 * Description: Brute force(rank) 
 */
#include<stdio.h>
#include<stdlib.h>

int main() {
    int size;
    int rank = 0;
    int** table;

    scanf("%d", &size);

    table = (int**)malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++) {
        table[i] = (int*)malloc(sizeof(int) * 2);
    }

    for(int i = 0; i < size; i++) {
        scanf("%d %d", &table[i][0], &table[i][1]);
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (i == j) continue;
            if (table[i][0] < table[j][0] && table[i][1] < table[j][1]) {
                rank++;
            }
        }
        printf("%d", rank + 1);
        if (i != size - 1) printf(" ");
        rank = 0;
    }

    for(int i = 0; i < size; i++) {
        free(table[i]);
        table[i] = NULL;
    }
    free(table);
    table = NULL;
    return 0;
}