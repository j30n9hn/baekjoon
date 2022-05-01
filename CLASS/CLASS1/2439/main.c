#include <stdio.h>

int main() {
	int num;

	scanf("%d", &num);
	for (int j = 1; j <= num; j++) {
		for (int i = num; i > j; i--) {
			printf(" ");
		}
		for (int k = 0; k < j; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
