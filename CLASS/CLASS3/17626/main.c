/*
 * Description:
 *  - Math-based solution using number theory
 *  - Lagrange's Four Square Theorem
 *  - Legendre's Three Square Theorem
 *  - Time Complexity: O(sqrt(n))
 *  - Space Complexity: O(1)
 */

#include <stdio.h>
#include <math.h>

int isSquares(int number);
int calMinSquares(int number);

int main() {
    int number;
    
    scanf("%d", &number);
    printf("%d\n", calMinSquares(number));

    return 0;
}

int isSquares(int number) {
    int root = (int)sqrt(number);
    return root * root == number;
}

int calMinSquares(int number) {
    if (number == 0) return 0;
    if (isSquares(number)) return 1;
    int cal;
    
    for (cal = 1; cal * cal <= number; cal++) {
        if (isSquares(number - cal * cal)) return 2;
    }
    
    cal = number;
    while (cal % 4 == 0) cal /= 4;

    if (cal % 8 == 7) return 4;
    else return 3;
}
