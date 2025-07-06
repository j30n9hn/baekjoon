/*
 * Description: Dynamic Programming 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* zero;
    int* one;
} number;

void initCount(number* count, int num);
void freeCount(number* count);

void fibonacci(number* count, int n);

int main() {
    int cnt;
    int num;
    int zero = 0;
    int one = 0;
    number number;
    
    scanf("%d", &cnt);
    
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num);
        initCount(&number, num);

        number.zero[0] = 1;
        number.one[0] = 0;
        if (num >= 1) {
            number.zero[1] = 0;
            number.one[1] = 1;
        }
        fibonacci(&number, num);
        printf("%d %d\n", number.zero[num], number.one[num]);
        freeCount(&number);
    }

    return 0;
}

void initCount(number* count, int num) {
    count->zero = (int*)malloc(sizeof(int) * (num + 2));
    count->one = (int*)malloc(sizeof(int) * (num + 2));
    for (int i = 0; i <= num + 1; i++) {
        count->zero[i] = 0;
        count->one[i] = 0;
    }
}

void freeCount(number* count) {
    free(count->zero);
    count->zero = NULL;
    free(count->one);
    count->one = NULL;
}

void fibonacci(number* count, int n) {
    for (int i = 2; i <= n; i++) {
        count->zero[i] = count->zero[i - 1] + count->zero[i - 2];
        count->one[i] = count->one[i - 1] + count->one[i - 2];
    }
}