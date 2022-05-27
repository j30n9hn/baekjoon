#include <stdio.h>

int main() {
	int n, k;
	int nf, kf, nmkf;
	int sol;

	scanf("%d %d", &n, &k);
	nf = n;
	kf = k;
	nmkf = n - k;
	for (int i = n - 1; i >= 1; i--) {
		nf *= i;
	}
	for (int i = k - 1; i >= 1; i--) {
		kf *= i;
	}
	for (int i = n - k - 1; i >= 1; i--) {
		nmkf *= i;
	}
	sol = nf / (kf * nmkf);
	printf("%d", sol);
	return 0;
}
