#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int size[6] = { 0, };
    int t;
    int p;
    int ts = 0;
    int ps = 0;
    int pea = 0;

    scanf("%d", &n);

    for(int i = 0; i < 6; i++) {
        scanf("%d", &size[i]);
    }
    scanf("%d %d", &t, &p);

    for (int i = 0; i < 6; i++) {
        if (size[i] == 0) continue;
        else if (size[i] <= t) ts++;
        else if (size[i] % t == 0) ts += (size[i] / t);
        else ts += (size[i] / t + 1);
    }

    ps = n / p;
    pea = n % p;

    printf("%d\n%d %d\n", ts, ps, pea);







    return 0;
}