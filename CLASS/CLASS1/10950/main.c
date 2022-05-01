#include <stdio.h>

int main() {
	int a, b;
	int t;

	scanf("%d", &t);
	
	int sol[t];

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		sol[i] = a + b;
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", sol[i]);
	}
	return 0;
}
