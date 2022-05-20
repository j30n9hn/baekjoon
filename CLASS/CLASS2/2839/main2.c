#include <stdio.h>

int main() {
    int n;
    int five = 5;
    int tmp;

    //scanf("%d", &n);
	for(n = 3; n <= 5000; n++) {
    if (n % 5 == 0) {
		printf("n = %d\n", n);
		printf("%d\n", n /5);
    } else if ((n % 5) % 3 == 0) {
		printf("n = %d\n", n);
		printf("%d\n", (n / 5) + ((n % 5) / 3));
    } else if (n % 3 == 0) {
		printf("n = %d\n", n);
        printf("%d\n", n / 3);
    } else {
        for (int i = 1000; i >= 1; i--) {
			tmp = n - five * i;
			if (tmp < 0) {
				continue;
			}
			if (tmp % 3 == 0) {
				printf("n = %d\n", n);
                printf("%d\n", i + (tmp / 3));
				break;
            }
        }
		//printf("lim-1lim");
    }
	}
	return 0;
}
