#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char input1[9];
    char input2[9];
    char input3[9];
    char output[64][9];
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int index = 0;

    scanf("%s", input1);
    scanf("%s", input2);
    scanf("%s", input3);
    

    if ((strcmp(input1, "Fizz") != 0) && (strcmp(input1, "Buzz") != 0) && (strcmp(input1, "FizzBuzz") != 0)) {
        num1 = atoi(input1);
    }

    if ((strcmp(input2, "Fizz") != 0) && (strcmp(input2, "Buzz") != 0) && (strcmp(input2, "FizzBuzz") != 0)) {
        num2 = atoi(input2);
    }

    if ((strcmp(input3, "Fizz") != 0) && (strcmp(input3, "Buzz") != 0) && (strcmp(input3, "FizzBuzz") != 0)) {
        num3 = atoi(input3);
    }

    if (num1 != 0) {
        for (int i = num1; i < num1 + 55; i++) {
            if (i % 15 == 0) {
                sprintf(output[index], "%s", "FizzBuzz");
            } else if (i % 3 == 0) {
                sprintf(output[index], "%s", "Fizz");
            } else if (i % 5 == 0) {
                sprintf(output[index], "%s", "Buzz");
            } else {
                sprintf(output[index], "%d", i);
            }
            index++;
        }
        index = 0;
    } else if (num2 != 0) {
        for (int i = num2 - 1; i < num2 + 54; i++) {
            if (i % 15 == 0) {
                sprintf(output[index], "%s", "FizzBuzz");
            } else if (i % 3 == 0) {
                sprintf(output[index], "%s", "Fizz");
            } else if (i % 5 == 0) {
                sprintf(output[index], "%s", "Buzz");
            } else {
                sprintf(output[index], "%d", i);
            }
            index++;
        }
        index = 0;
    } else {
        for (int i = num3 - 2; i < num3 + 53; i++) {
            if (i % 15 == 0) {
                sprintf(output[index], "%s", "FizzBuzz");
            } else if (i % 3 == 0) {
                sprintf(output[index], "%s", "Fizz");
            } else if (i % 5 == 0) {
                sprintf(output[index], "%s", "Buzz");
            } else {
                sprintf(output[index], "%d", i);
            }
            index++;
        }
        index = 0;
    }
    
    if (num1 != 0) {
        for (int i = num1; i < num1 + 50; i++) {
            if ((strcmp(output[index], input1) == 0) && (strcmp(output[index + 1], input2) == 0) && (strcmp(output[index + 2], input3) == 0)) {
                printf("%s\n", output[index+3]);
                break;
            }
            index++;
        }
    } else if (num2 != 0) {
        for (int i = num2 - 1; i < num2 + 49; i++) {
            if ((strcmp(output[index], input1) == 0) && (strcmp(output[index + 1], input2) == 0) && (strcmp(output[index + 2], input3) == 0)) {
                printf("%s\n", output[index+3]);
                break;
            }
            index++;
        }
    } else {
        for (int i = num3 - 2; i < num3 + 48; i++) {
            if ((strcmp(output[index], input1) == 0) && (strcmp(output[index + 1], input2) == 0) && (strcmp(output[index + 2], input3) == 0)) {
                printf("%s\n", output[index+3]);
                break;
            }
            index++;
        }
    }

    return 0;
}