#include <stdio.h>
#include <stdint.h>

int main() {
	int i;
	 r = 1;

	scanf("%d", &i);

	for (int j = 0; j < i; j++) {
		r *= 31;
	}
	printf("%ld", r);

	return 0;
}
