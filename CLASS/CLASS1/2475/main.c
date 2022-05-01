#include <stdio.h>

int main() {
	int num[5];
	int sol = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
		sol += (num[i] * num[i]);
	}
	printf("%d", sol % 10);
	return 0;
}
