#include <stdio.h>

int num[1000000];

int main() {
	int n;
	int max = -1000000;
	int min = 1000000;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n; i++) {
		if (max <= num[i]) {
			max = num[i];
		}
		if (min >= num[i]) {
			min = num[i];
		}
	}
	printf("%d %d", min, max);
	return 0;
}
