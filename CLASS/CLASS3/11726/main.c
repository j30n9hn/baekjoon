/*
 * Description: Dynamic Programming
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* method;
} tiling;

void initTiling(tiling* tile, int index);
void freeTiling(tiling* tile);
int culTiling(tiling* tile, int index);

int main() {
    int n;
    tiling tile;
    scanf("%d", &n);
    initTiling(&tile, n);
    printf("%d\n", culTiling(&tile, n));
    freeTiling(&tile);

    return 0;
}

void initTiling(tiling* tile, int index) {
    tile->method = (int*)calloc(index + 1, sizeof(int));
    tile->method[0] = 0;
    if (index >= 1) tile->method[1] = 1;
    if (index >= 2) tile->method[2] = 2;
}

void freeTiling(tiling* tile) {
    free(tile->method);
    tile->method = NULL;
}

int culTiling(tiling* tile, int index) {
    if (index <= 0) return 0;
    if (tile->method[index] != 0) return tile->method[index];

    tile->method[index] = (culTiling(tile, index - 1) + culTiling(tile, index - 2)) % 10007;
    return tile->method[index];
}
