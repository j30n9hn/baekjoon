#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char input[5];
    char s1[16] = "";
    char s2[16] = "";
    char space[] = " ";
    char* s1p = s1;
    char* s2p = s2;
    char* end;
    int numa, numb, numc, numab;

    for (int i = 0; i < 3; i++) {
        scanf("%4s", input);
        strncat(s1, input, sizeof(s1) - strlen(s1) -1);
        if (i == 2) continue;
        strncat(s2, input, sizeof(s2) - strlen(s2) -1);
        strncat(s1, space, sizeof(s1) - strlen(s1) -1);
    }

    numa = strtol(s1p, &end, 0);
    numb = strtol(end, &end, 0);
    numc = strtol(end, NULL, 0);
    numab = strtol(s2p, NULL, 0);

    printf("%d\n", numa + numb - numc);
    printf("%d", numab - numc);

    return 0;
}