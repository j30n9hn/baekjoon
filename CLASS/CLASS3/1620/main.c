/*
 * Description: Hashmap and BinarySearch
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int pocketmonNo;
    char pocketmonName[21];
} pocketmon;

int compare( const void* arg1, const void* arg2);

int main() {
    char problem[21];
    int pocketmonAmount;
    int problemAmount;
    int start, mid, end;
    pocketmon* pokedex;
    pocketmon* sortedPokedex;

    scanf("%d %d", &pocketmonAmount, &problemAmount);

    pokedex = (pocketmon*)malloc(sizeof(pocketmon) * pocketmonAmount);
    sortedPokedex = (pocketmon*)malloc(sizeof(pocketmon) * pocketmonAmount);
    for (int i = 0; i < pocketmonAmount; i++) {
        pokedex[i].pocketmonNo = i + 1;
        sortedPokedex[i].pocketmonNo = i + 1;
        scanf("%s", pokedex[i].pocketmonName);
        strcpy(sortedPokedex[i].pocketmonName, pokedex[i].pocketmonName);
    }

    qsort(sortedPokedex, pocketmonAmount, sizeof(pocketmon), compare);
    
    for (int i = 0; i < problemAmount; i++) {
        scanf("%s", problem);
        if(atoi(problem) != 0) {
            printf("%s\n", pokedex[atoi(problem) - 1].pocketmonName);
        } else {
            end = pocketmonAmount - 1;
            start = 0;
            while (start <= end) {
                mid = (start + end) / 2;
                if (strcmp(problem, sortedPokedex[mid].pocketmonName) == 0) {
                    printf("%d\n", sortedPokedex[mid].pocketmonNo);
                    break;
                } else if (strcmp(problem, sortedPokedex[mid].pocketmonName) < 0) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
    }

    free(pokedex);
    pokedex = NULL;

    free(sortedPokedex);
    sortedPokedex = NULL;

    return 0;
}

int compare( const void* arg1, const void* arg2) {
    const pocketmon* name1 = (const pocketmon*)arg1;
    const pocketmon* name2 = (const pocketmon*)arg2;

    return strcmp(name1->pocketmonName, name2->pocketmonName);
}