#include <stdio.h>

int main() {
	int n, k;
	int sol;
	int i, j , nmk;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		i *= i;
	}
	for (j = 1; j <= k; j++) {
		j *= j;
	}
	for (nmk = 1; nmk <= n - k; nmk++) {
		nmk *= nmk;
	}
	if (k == 0) {
		j = 1;
	}
	sol = i / (j * nmk);
	printf("%d", sol);
	return 0;
}
