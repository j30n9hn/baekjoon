/*
 * Description: Dynamic Programming (Bottom-up)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* method;
} tiling;

void initTiling(tiling* tile, int index);
void freeTiling(tiling* tile);
int calcTiling(tiling* tile, int index);

int main() {
    int n;
    tiling tile;

    scanf("%d", &n);
    initTiling(&tile, n);

    printf("%d\n", calcTiling(&tile, n));

    freeTiling(&tile);
    return 0;
}

void initTiling(tiling* tile, int index) {
    tile->method = (int*)calloc(index + 1, sizeof(int));
    tile->method[0] = 1;
    if (index >= 1) tile->method[1] = 1;
    if (index >= 2) tile->method[2] = 3;
    if (index >= 3) tile->method[3] = 5;
}

void freeTiling(tiling* tile) {
    free(tile->method);
    tile->method = NULL;
}

int calcTiling(tiling* tile, int index) {
    for (int i = 4; i <= index; i++) tile->method[i] = (tile->method[i - 1] + 2 * tile->method[i - 2]) % 10007;
    return tile->method[index];
}
