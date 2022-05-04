#include <stdio.h>

int main() {
	int n;
	int dis;
	int room = 8;
	int cnt = 0;
	int max = 11;

	scanf("%d", &n);

	if (n == 1) {
		dis = 1;
		printf("%d", dis);
	} else if ((n >= 2) && (n <= 7)) {
		dis = 2;
		printf("%d", dis);
	} else {
		dis = 3;
		for (; ; room++) {
			for (int j = 1; cnt < max; ) {
				if (room == n) {
					break;
				}
				room += j;
				cnt++;
			}
			cnt = 0;
			max += 6;
			if (room == n) {
				break;
			}
			dis++;
		}
		printf("%d", dis);
	}
	return 0;
}
