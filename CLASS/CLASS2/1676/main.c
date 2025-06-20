/*
 * Description: Math Implementation (Factorial) 
 * If a number includes both 2 and 5 as factors, it results in a trailing zero.
 * The number of trailing zeros depends on how many times 5 appears as a factor,
 * because even numbers (which provide factors of 2) are more common than multiples of 5.
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