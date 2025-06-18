#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[3][9];
    int num;

    for (int i = 0; i < 3; i++) {
        scanf("%s", input[i]);
        if ((strcmp(input[i], "Fizz") != 0) && (strcmp(input[i], "Buzz") != 0) && (strcmp(input[i], "FizzBuzz") != 0)) {
            num = atoi(input[i]) + 3 - i;
        }
    }

    if (num % 15 == 0) {
        printf("FizzBuzz\n");
    } else if (num % 3 == 0) {
        printf("Fizz\n");
    } else if (num % 5 == 0) {
        printf("Buzz\n");
    } else {
        printf("%d\n", num);
    }

    return 0;
}
