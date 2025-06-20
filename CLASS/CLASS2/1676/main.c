/*
 * Description: Math Implementation (Factorial) 
 */
#include<stdio.h>

int main() {
    int input;
    int cnt = 0;

    scanf("%d", &input);

    for (int i = 1; i <= input; i++) {
        if (i % 5 == 0) cnt++;
        if (i % 25 == 0) cnt++;
        if (i % 125 == 0) cnt++;
    }    
    printf("%d\n", cnt);

    return 0;
}