/* 
 * Description: Math Implementation
 */
#include<stdio.h>

int getCheckCode(char input[14]);
int getEliminatedCode(int index, char input[14]);

int main() {
    char input[14];
    int validator = 0;
    int index = -1;
    

    scanf("%s", input);

    for (int i = 0; i < 14; i++) {
        if(input[i] == '*') {
            index = i;
            break;
        }
    }


    if (index == 12) {
        validator = getCheckCode(input);
    } else {
        validator = getEliminatedCode(index, input);
    }

    printf("%d\n", validator);



    return 0;
}

int getCheckCode(char input[14]) {
    int validator = 0;
    int checkCode = 0;
    for (int i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            validator += input[i] - '0';
        } else {
            validator += (input[i] - '0') * 3;
        }
    }
    checkCode = (10 - (validator % 10)) % 10;
    return checkCode;
}

int getEliminatedCode(int index, char input[14]) {
    int validator = 0;
    int checkCode = input[12] - '0';
    int eliminatedCode;


    for (int i = 0; i < index; i++) {
        if (i % 2 == 0) {
            validator += input[i] - '0';
        } else {
            validator += (input[i] - '0') * 3;
        }
    }


    for (int i = index + 1; i < 12; i++) {
        if (i % 2 == 0) {
            validator += input[i] - '0';
        } else {
            validator += (input[i] - '0') * 3;
        }
    }



    if (index % 2 == 0) {
        for (int i = 0; i < 10; i++) {
            if ((10 - ((validator + i) % 10 )) % 10 == checkCode) {
                eliminatedCode = i;
                break;
            }
        }
    } else {
        for (int i = 0; i < 10; i++) {
            if ((10 - ((validator + i * 3) % 10)) % 10 == checkCode) {
                eliminatedCode = i;
                break;
            }
        }
    }
    return eliminatedCode;
}