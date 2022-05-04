#include <stdio.h>

int main() {
	int n;
	int m;
	int dupi;
	int tempn;

	scanf("%d", &n);

	for (int i = 0; i <= n; i++) {
		tempn = i;
		dupi = i;
		for (int j = 1000000; j > 0; j /= 10) {
			if ((dupi / j) <= 0) {
				continue;
			}
			tempn += dupi / j;
			dupi -= (dupi / j) * j;
			}
		if (tempn == n) {
			m = i;
			break;
		}
		m = 0;
	}
	printf("%d", m);
	return 0;
}
