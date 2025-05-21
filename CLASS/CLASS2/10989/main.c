#include<stdio.h>
// Counting Sort

int main() {
    int num = 0;
    int cnt;
    int flag = 0;
    int count[10001] = { 0, };


    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num);
        count[num]++;
    }

    for (int i = 0; i < 10001; i++) {
        for(int j = count[i]; j > 0; j--) {
            printf("%d\n", i);
        }
    }

    return 0;
}