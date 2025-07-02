/*
 * Description: Binary Search
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char unknownPerson[21];
}unknownPerson;

typedef struct {
    char neverHeardPerson[21];
}neverHeardPerson;

typedef struct {
    char neverSeenPerson[21];
}neverSeenPerson;

int compareHeard(const void* arg1, const void* arg2);
int compareSeen(const void* arg1, const void* arg2);

int main() {
    int start, mid, end;
    int unknownCount;
    int neverHeardAmount;
    int neverSeenAmount;
    int unknownPeopleAmount;
    unknownPerson* unknownPeople;
    neverHeardPerson* neverHeardPeople;
    neverSeenPerson* neverSeenPeople;

    // Make Groups
    scanf("%d %d", &neverHeardAmount, &neverSeenAmount);

    if (neverHeardAmount > neverSeenAmount) unknownPeopleAmount = neverSeenAmount;
    else unknownPeopleAmount = neverHeardAmount;
    unknownPeople = (unknownPerson*)malloc(sizeof(unknownPerson) * unknownPeopleAmount);
    neverHeardPeople = (neverHeardPerson*)malloc(sizeof(neverHeardPerson) * neverHeardAmount);
    neverSeenPeople = (neverSeenPerson*)malloc(sizeof(neverSeenPerson) * neverSeenAmount);

    // Set Never groups
    for (int i = 0; i < neverHeardAmount; i++) {
        scanf("%s", neverHeardPeople[i].neverHeardPerson);
    }

    for (int i = 0; i < neverSeenAmount; i++) {
        scanf("%s", neverSeenPeople[i].neverSeenPerson);
    }

    // Sort Never groups
    qsort(neverHeardPeople, neverHeardAmount, sizeof(neverHeardPerson), compareHeard);
    qsort(neverSeenPeople, neverSeenAmount, sizeof(neverSeenPerson), compareSeen);

    if (neverHeardAmount <= neverSeenAmount) {
        unknownCount = 0;
        for (int i = 0; i < neverHeardAmount; i++) {
            start = 0;
            end = neverSeenAmount - 1;
            while (start <= end) {
                mid = (start + end) / 2;
                if (strcmp(neverHeardPeople[i].neverHeardPerson, neverSeenPeople[mid].neverSeenPerson) == 0) {
                    strcpy(unknownPeople[unknownCount].unknownPerson, neverHeardPeople[i].neverHeardPerson);
                    unknownCount++;
                    break;
                } else if (strcmp(neverHeardPeople[i].neverHeardPerson, neverSeenPeople[mid].neverSeenPerson) > 0) {
                    start = mid + 1;
                } else {
                    end = mid -1;
                }
            }
        }
    } else {
        unknownCount = 0;
        for (int i = 0; i < neverSeenAmount; i++) {
            start = 0;
            end = neverHeardAmount - 1;
            while (start <= end) {
                mid = (start + end) / 2;
                if (strcmp(neverSeenPeople[i].neverSeenPerson, neverHeardPeople[mid].neverHeardPerson) == 0) {
                    strcpy(unknownPeople[unknownCount].unknownPerson, neverSeenPeople[i].neverSeenPerson);
                    unknownCount++;
                    break;
                } else if (strcmp(neverSeenPeople[i].neverSeenPerson, neverHeardPeople[mid].neverHeardPerson) > 0) {
                    start = mid + 1;
                } else {
                    end = mid -1;
                }
            }
        }
    }

    // Print flag
    printf("%d\n", unknownCount);
    for (int i = 0; i < unknownCount; i++) {
        printf("%s\n", unknownPeople[i].unknownPerson);
    }

    // Free every groups
    free(unknownPeople);
    free(neverHeardPeople);
    free(neverSeenPeople);
    return 0;
}

int compareHeard(const void* arg1, const void* arg2) {
    const neverHeardPerson* name1 = (const neverHeardPerson*)arg1;
    const neverHeardPerson* name2 = (const neverHeardPerson*)arg2;
    return strcmp(name1->neverHeardPerson, name2->neverHeardPerson);
}

int compareSeen(const void* arg1, const void* arg2) {
    const neverSeenPerson* name1 = (const neverSeenPerson*)arg1;
    const neverSeenPerson* name2 = (const neverSeenPerson*)arg2;
    return strcmp(name1->neverSeenPerson, name2->neverSeenPerson);
}