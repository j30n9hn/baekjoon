#include <stdio.h>

int main() {
	int w[100], h[100], d[100];
	int i = 0;
	int max = 0;

	for (i = 0; ; i++) {
		scanf("%d %d %d", &w[i], &h[i], &d[i]);
		if ((w[i] == 0) && (h[i] == 0) && (d[i] == 0)) {
			break;
		}
	}

	int sqew[i], sqeh[i], sqed[i];

	for (int k = 0; k < i; k++) {
		sqew[k] = w[k] * w[k];
		sqeh[k] = h[k] * h[k];
		sqed[k] = d[k] * d[k];
	}
	for (int j = 0; j < i; j++) {
		if (sqew[j] == sqeh[j] + sqed[j]) {
			printf("right\n");
		} else if (sqeh[j] == sqew[j] + sqed[j]) {
			printf("right\n");
		} else if (sqed[j] == sqew[j] + sqeh[j]) {
			printf("right\n");
		} else {
			printf("wrong\n");
		}
	}
	return 0;
}
