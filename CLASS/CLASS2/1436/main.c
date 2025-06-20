/*
 * Description: Brute force 
 */
#include<stdio.h>
#include<string.h>

int main() {
    char validator[1000000];
    int cnt = 0;
    int input;

    scanf("%d", &input);

    for (int i = 666; ; i++) {
        sprintf(validator, "%d", i);
        if (strstr(validator, "666") != 0) {
            cnt++;
        }
        if (cnt == input) {
            printf("%s\n", validator);
            break;
        }
    }



    return 0;
}