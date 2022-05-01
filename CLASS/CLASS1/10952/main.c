#include <stdio.h>

int arr[1000000];

int main() {
	int a, b;
	int cnt = 0;

	for ( ; ; ) {
		scanf("%d %d", &a, &b);
		if ((a == 0) && (b == 0)) {
				break;
		}
		arr[cnt] = a + b;
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
