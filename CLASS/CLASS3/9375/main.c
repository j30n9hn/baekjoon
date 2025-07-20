/*
 * Description: Combinatorics, Hash Map
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char category[21];
    char name[21];
} wearInfo;

int compare(const void* arg1, const void* arg2);

int main() {
    int numberOfTestCases;
    int numberOfWears;
    int count;
    int combination;
    wearInfo wear[30];

    scanf("%d", &numberOfTestCases);

    for (int i = 0; i < numberOfTestCases; i++) {
        count = 1;
        combination = 1;

        scanf("%d", &numberOfWears);
        if (numberOfWears == 0) {
            printf("%d\n", numberOfWears);
            continue;
        }
        for (int j = 0; j < numberOfWears; j++) {
            scanf("%s%s", wear[j].name, wear[j].category);
        }

        qsort(wear, numberOfWears, sizeof(wearInfo), compare);

        for (int j = 1; j < numberOfWears; j++) {
            if (strcmp(wear[j].category, wear[j - 1].category) == 0) {
                count++;
            } else {
                combination *= count + 1;
                count = 1;
            }
        }
        combination *= count + 1;
        printf("%d\n", combination - 1);
    }


    return 0;
}

int compare(const void* arg1, const void* arg2) {
    wearInfo firstWear = *(wearInfo*)arg1;
    wearInfo secondWear = *(wearInfo*)arg2;

    return strcmp(firstWear.category, secondWear.category);
}