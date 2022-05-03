#include <stdio.h>
#include <stdlib.h>

int main() {
	int tcase;
	int best = 101;
	int allocfloor;
	int allocroom;

	scanf("%d", &tcase);

	int* h = (int*)malloc(sizeof(int) * tcase);
	int* w = (int*)malloc(sizeof(int) * tcase);
	int* n = (int*)malloc(sizeof(int) * tcase);

	for (int i = 0; i < tcase; i++) {
		scanf("%d %d %d", &h[i], &w[i], &n[i]);
	}
	for (int i = 0; i < tcase; i++) {
		allocroom = 0;
		for (int j = 0; j < w[i]; j ++) {
			allocfloor = j + 1;
			for (int k = 0; k < h[i]; k++) {
				if (allocroom == n[i]) {
					break;
				}
				allocfloor += 100;
				allocroom++;
			}
			if(allocroom == n[i]) {
				break;
			}
		}
		printf("%d\n", allocfloor);
	}
	free(h);
	free(w);
	free(n);
	return 0;
}
