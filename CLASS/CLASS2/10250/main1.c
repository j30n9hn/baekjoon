#include <stdio.h>
#include <stdlib.h>

int main() {
	int tcase;
	int best = 101;
	int allocroom, allocfloor;
	int pos;

	scanf("%d", &tcase);
	
	int* h = (int*)malloc(sizeof(int) * tcase);
	int* w = (int*)malloc(sizeof(int) * tcase);
	int* n = (int*)malloc(sizeof(int) * tcase);
	
	for (int i = 0; i < tcase; i++) {
		scanf("%d %d %d", &h[i], &w[i], &n[i]);
	}
	for (int i = 0; i < tcase; i++) {
		int** hotel = (int**)malloc(sizeof(int*) * h[i]);
		for (int j = 0; j < h[i] + 1; j++) {
			hotel[j] = (int*)malloc(sizeof(int) * w[i]);
		}
		for (int q = 0; q < h[i]; q++) {
			for (int k = 0; k < w[i]; k++) {
				hotel[q][k] = best;
				best++;
			}
			best = 101 + ((q + 1) * 100);
		}
		allocroom = n[i] / h[i];
		allocfloor = n[i] % h[i];
		pos = hotel[allocfloor - 1][allocroom];
		printf("%d\n", pos);
		for (int t = 0; t < h[i] + 1; t++) {
			free(hotel[t]);
		}
		free(hotel);
	}
	free(h);
	free(w);
	free(n);
	return 0;
}
