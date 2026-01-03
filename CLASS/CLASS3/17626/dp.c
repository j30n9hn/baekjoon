/*
 * Description: Dynamic Programming (Bottom-Up)
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    int* minSquares;

    scanf("%d", &number);
    minSquares = (int*)calloc(number + 1, sizeof(int));
    minSquares[0] = 0;
    for (int i = 1; i <= number; i++){
        minSquares[i] = i;
        for (int j = 1; j * j <= i; j++) {
            if (minSquares[i] > minSquares[i - j*j] + 1) 
                minSquares[i] = minSquares[i - j*j] + 1;
        }
    }
    printf("%d\n", minSquares[number]);

    free(minSquares);
    minSquares = NULL;
    return 0;
}
