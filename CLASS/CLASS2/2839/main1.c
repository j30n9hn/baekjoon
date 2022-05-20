#include <stdio.h>

int main() {
	int n;
	int five = 5;
	int three = 3;
	int tmp;
	int cmp1, cmp2;
	int min;

	scanf("%d", &n);

	if ((n % 5) % 3 == 0) {
		printf("%d", (n / 5) + ((n % 5) / 3));
	} else if (n % 5 == 0) {
		printf("%d", n / 5);
	} else if (n % 3 == 0) {
		printf("%d", n / 3);	
	} else {
		for (int i = 1; i <= 1000; i++) {
			tmp = n - five * i;
			if (tmp < 0) {
				printf("-1");
				break;
			}
			if (tmp % 3 == 0) {
				cmp1 = i + (tmp / 3);
				if (i != 1) {
					cmp2 = (i - 1) + ((tmp + 5) / 3);
				}
			} 
			if ((cmp1 < cmp2) && (cmp1 > 0) && (i != 1)) {
				min = cmp1;
			}
			if ((cmp2 < cmp1) && (cmp2 > 0) && (i != 1)) {
				min = cmp2;
			}
		}
		printf("%d", min);
	}

	return 0;
}
