#include <stdio.h>

int main() {
    int n;
    int five = 5;
    int tmp;
	int tmp2;
	int btmp;
    //scanf("%d", &n);
	for (n = 3; n <= 5000; n++) {
    if (n % 5 == 0) {
		printf("n = %d\n", n);
		printf("%d\n", n /5);
    } else if ((n % 5) % 3 == 0) {
		printf("n = %d\n", n);
		printf("%d\n", (n / 5) + ((n % 5) / 3));
    } else {
        for (int i = 1000; i >= 1; i--) {
			tmp = n - five * i;
			if (tmp < 0) {
				continue;
			}
			if (tmp % 3 == 0) {
				tmp2 = n / 3;
                btmp = i + (tmp / 3);
				if (tmp2 < btmp) {
					printf("n = %d\n", n);
					printf("%d\n", tmp2);
					break;
				} else {
					printf("n = %d\n", n);
					printf("%d\n", btmp);
					break;
				}
				//return 0;
            }
        }
    }
	/*if (n % 3 == 0) {
		printf("n = %d\n", n);
		printf("%d\n", n / 3);
	}*/
	}
	return 0;
}
