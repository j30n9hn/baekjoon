#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int fac;
	int pos = 0;
	int max = 0;

	scanf("%d %d", &n, &m);
	fac = n * (n - 1) * (n - 2);
	int* cnum = (int*)malloc(sizeof(int) * n);
	int* totcnum = (int*)malloc(sizeof(int) * fac);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cnum[i]);
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (j == i) {
				continue;
			}
			for (int k = 2; k < n; k++) {
				if ((k == i) || (k == j)) {
					continue;
				}
				totcnum[pos] = cnum[i] + cnum[j] + cnum[k];
				pos++;
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 1; j <= n; j++) {
			if (totcnum[j] < totcnum[j - 1]) {
				max = totcnum[j - 1];
				totcnum[j - 1] = totcnum[j];
				totcnum[j] = max;
			}
		}
	}
	max = 0;
	for (int i = 0; i < fac; i++) {
		if (totcnum[i] == m) {
			printf("%d", totcnum[i]);
			break;
		}
		if (totcnum[i] > m) {
			printf("%d", totcnum[i - 1]);
			break;
		}
	}
	free(cnum);
	free(totcnum);
	return 0;
}

