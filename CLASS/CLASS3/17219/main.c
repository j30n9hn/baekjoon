/*
 * Description: Set
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char url[21];
    char password[21];
} passwordInfor;

int compare(const void* arg1, const void* arg2);

int main() {
    int start, mid, end;
    int savedSiteCount;
    int targetCount;
    passwordInfor* site;
    passwordInfor* target;

    scanf("%d %d", &savedSiteCount, &targetCount);
    site = (passwordInfor*)malloc(sizeof(passwordInfor) * savedSiteCount);
    for (int i = 0; i < savedSiteCount; i++) {
        scanf("%s", site[i].url);
        scanf("%s", site[i].password);
    }
    qsort(site, savedSiteCount, sizeof(passwordInfor), compare);

    target = (passwordInfor*)malloc(sizeof(passwordInfor) * targetCount);
    for (int i = 0; i < targetCount; i++) {
        scanf("%s", target[i].url);
    }

    for (int i = 0; i < targetCount; i++) {
        start = 0;
        end = savedSiteCount - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (strcmp(target[i].url, site[mid].url) == 0) {
                printf("%s\n", site[mid].password);
                break;
            } else if (strcmp(target[i].url, site[mid].url) < 0) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
    }

    free(site);
    site = NULL;
    free(target);
    target = NULL;

    return 0;
}

int compare(const void* arg1, const void* arg2) {
    const passwordInfor* site1 = (const passwordInfor*)arg1;
    const passwordInfor* site2 = (const passwordInfor*)arg2;

    return strcmp(site1->url, site2->url);
}