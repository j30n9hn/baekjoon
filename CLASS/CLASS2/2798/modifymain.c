#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int max = 0;
	int tot;

	scanf("%d %d", &n, &m);
	
	int* cardnum = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cardnum[i]);
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (j == i) {
				continue;
			}
			for (int k = 2; k < n; k++) {
				if ((k == j) || (k == i)) {
					continue;
				}
				tot = cardnum[i] + cardnum[j] + cardnum[k];
				if ((max <= tot) && (tot <= m)) {
					max = tot;
				}
			}
		}
	}
	printf("%d", max);
	free(cardnum);
	return 0;
}
