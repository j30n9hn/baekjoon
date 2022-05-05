#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int fac;

	scanf("%d %d", &n, &m);
	fac = n * (n - 1) * (n - 2);
	int* cnum = (int*)malloc(sizeof(int) * n);
	int* totcnum = (int*)malloc(sizeof(int) * fac);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cnum[i]);
	}
	return 0;
}

