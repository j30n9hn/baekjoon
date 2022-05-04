#include <stdio.h>

int main() {
	int n;
	int m;// m <= 99995
	int tempn;
	int num;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		if (i < 10) {
			tempn = i + i;
			if (tempn == n) {
				m = i;
				break;
			}
		} else if (i < 100) {	
			tempn = i;
			num = i;
			for (int j = 10; j > 0; j /= 10) {
				tempn += num / j;
				num -= (i / j) * j;
			}
			if (tempn == n) {
				m = i;
				break;
			}
		} else if (i < 1000) {
			tempn = i;
			num = i;
			for (int j = 100; j > 0; j /= 10) {
				tempn += num / j;
				num -= (i / j) * j;
			}
			if (tempn == n) {
				m = i;
				break;
			}
		} else if (i < 10000) {
			tempn = i;
			num = i;
			for (int j = 1000; j > 0; j /= 10) {
				tempn += num / j;
				num -= (i / j) * j;
			}
			if (tempn == n) {
				m = i;
				break;
			}
		} else if (i < 100000) {
			tempn = i;
			num = i;
			for (int j = 10000; j > 0; j /= 10) {
				tempn += num / j;
				num -= (i / j) * j;
			}
			if (tempn == n) {
				m = i;
				break;
			}
		} else {
				
		}
	}
	printf("%d", m);
	return 0;
}
