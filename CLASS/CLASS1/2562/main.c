#include <stdio.h>

int main() {
	int num[9];
	int max = 0;
	int pos;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &num[i]);
		if (max <= num[i]) {
			max = num[i];
			pos = i + 1;
		}
	}
	printf("%d\n%d", max, pos);
	return 0;
}
