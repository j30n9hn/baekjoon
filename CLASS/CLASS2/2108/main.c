/*
 * Description: Math Implementation (Mode)
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(const void* arg1, const void* arg2);
int getMode(int* arr, int loop);

int main() {
    int cnt;
    double sum = 0;
    double mean;
    int median;
    int mode;
    int range;
    int* arr;

    scanf("%d", &cnt);

    arr = (int*)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, cnt, sizeof(int), compare);
    
    for (int i = 0; i < cnt; i++) {
        sum += arr[i];
    }
    mean = round(sum / cnt);
    printf("%d\n", (int)mean);

    median = arr[cnt / 2];
    printf("%d\n", median);

    mode = getMode(arr, cnt);
    printf("%d\n", mode);

    range = arr[cnt - 1] - arr[0];
    printf("%d\n", range);

    free(arr);
    arr = NULL;
    return 0;
}

int compare(const void* arg1, const void* arg2) {
    int num1 = *(int*)arg1;
    int num2 = *(int*)arg2;
    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}

int getMode(int* arr, int loop) {
    int left = -4001;
    int right = -4001;
    int cnt = 1;
    int modeCnt = 0;

    if (loop == 1) return arr[0];

    for (int i = 1; i < loop; i++) {
        if (arr[i] == arr[i - 1]) {
            cnt++;
        } else {
            if (modeCnt < cnt) {
                modeCnt = cnt;
                left = arr[i - 1];
                right = -4001;
            } else if (modeCnt == cnt) {
                if (right == -4001) right = arr[i - 1];
            }
            cnt = 1;
        }
    }

    if (modeCnt < cnt) return arr[loop - 1];
    else if (cnt == modeCnt) {
        if (right == -4001) return arr[loop - 1];
        else return right;
    } else {
        if (right == -4001) return left;
        else return right;
    }
}