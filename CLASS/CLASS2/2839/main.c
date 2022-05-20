#include <stdio.h>

int main() {
	int n;
	int five = 5;
	int tmp;
	int tmp2;
	int btmp;

	scanf("%d", &n);
	if (n % 5 == 0) {
		printf("%d\n", n /5);
	} else if ((n % 5) % 3 == 0) {
		printf("%d\n", (n / 5) + ((n % 5) / 3));
	} else {
		for (int i = 1000; i >= 0; i--) {
			tmp = n - five * i;
			if (tmp < 0) {
				continue;
			}
			if (tmp % 3 == 0) {
				tmp2 = n / 3;
				btmp = i + (tmp / 3);
				if (tmp2 < btmp) {
					printf("%d", tmp2);
				} else {
					printf("%d", btmp);
				}
				return 0;
			}
		}
		printf("-1");
	}
	return 0;
}
