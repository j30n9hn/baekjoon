#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int max = 0;
	int temp = 0;

	scanf("%d %d", &n, &m);
	
	int* cardnum = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cardnum[i]);
	}
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (cardnum[i] < cardnum[i - 1]) {
				max = cardnum[i];
				cardnum[i] = cardnum[i - 1];
				cardnum[i - 1] = max;
			}
		}
	}
	max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) {
				continue;
			}
			for (int k = 0; k < n; k++) {
				if ((k == j) && (k == i)) {
					continue;
				}
				if (max < cardnum[i] + cardnum[j] + cardnum[k]) {
					temp = max;
					max = cardnum[i] + cardnum[j] + cardnum[k];
				}
				if (max == m) {
					printf("max = %d", max);
					free(cardnum);
					return 0;
				}
				if (max > m) {
					printf("temp = %d", temp);
					free(cardnum);
					return 0;
				}
			}
		}
	}
	return 0;
}
