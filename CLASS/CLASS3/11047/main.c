/*
 * Description: Binary search 
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int start, mid, end;
    int coinType; // N
    int goal; // K
    int coinCount;
    int* coin;

    scanf("%d %d", &coinType, &goal);
    coin = (int*)malloc(sizeof(int) * (coinType + 2));
    coin[0] = 0;
    coin[coinType + 1] = 100000001;
    for (int i = 1; i <= coinType; i++) {
        scanf("%d", &coin[i]);
    }

    start = 1;
    end = coinType + 1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (goal >= coin[mid] && goal < coin[mid + 1]) {
            break;
        } else if (goal >= coin[start] && goal <= coin[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    coinCount = 0;
    for(int i = mid; i > 0; i--) {
        if (goal % coin[i] == 0) {
            coinCount += goal / coin[i];
            break;
        }
        else {
            coinCount += goal / coin[i];
            goal = goal % coin[i];
        }
    }
    printf("%d\n", coinCount);

    free(coin);
    coin = NULL;

    return 0;
}