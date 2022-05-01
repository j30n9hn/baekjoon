#include <stdio.h>

int main() {
	int n, x;
	int num;
	int cnt = 0;

	scanf("%d %d", &n, &x);
	
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num < x) {
			arr[cnt] = num;
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
