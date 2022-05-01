#include <stdio.h>

int num[100000001];

int main() {
	int fir, sec, thi;
	int tot;
	int table[10] = { 0 };
	int much;

	scanf("%d %d %d", &fir, &sec, &thi);
	tot = fir * sec * thi;
	if (tot >= 100000000) {
		much = 9;
		num[0] = tot / 100000000;
		num[1] = (tot - num[0] * 100000000) / 10000000;
		num[2] = (tot - num[0] * 100000000 - num[1] * 10000000) / 1000000;
		num[3] = (tot - num[0] * 100000000 - num[1] * 10000000 - num[2] * 1000000) / 100000;
		num[4] = (tot - num[0] * 100000000 - num[1] * 10000000 - num[2] * 1000000 - num[3] * 100000) / 10000;
		num[5] = (tot - num[0] * 100000000 - num[1] * 10000000 - num[2] * 1000000 - num[3] * 100000 - num[4] * 10000) / 1000;
		num[6] = (tot - num[0] * 100000000 - num[1] * 10000000 - num[2] * 1000000 - num[3] * 100000 - num[4] * 10000 - num[5] * 1000) / 100;
		num[7] = (tot - num[0] * 100000000 - num[1] * 10000000 - num[2] * 1000000 - num[3] * 100000 - num[4] * 10000 - num[5] * 1000 - num[6] * 100) / 10;
		num[8] = (tot - num[0] * 100000000 - num[1] * 10000000 - num[2] * 1000000 - num[3] * 100000 - num[4] * 10000 - num[5] * 1000 - num[6] * 100 - num[7] * 10) / 1;
	} else if (tot >= 10000000) {
		much = 8;
		num[0] = tot / 10000000;
		num[1] = (tot - num[0] * 10000000) / 1000000;
		num[2] = (tot - num[0] * 10000000 - num[1] * 1000000) / 100000;
		num[3] = (tot - num[0] * 10000000 - num[1] * 1000000 - num[2] * 100000) / 10000;
		num[4] = (tot - num[0] * 10000000 - num[1] * 1000000 - num[2] * 100000 - num[3] * 10000) / 1000;
		num[5] = (tot - num[0] * 10000000 - num[1] * 1000000 - num[2] * 100000 - num[3] * 10000 - num[4] * 1000) / 100;
		num[6] = (tot - num[0] * 10000000 - num[1] * 1000000 - num[2] * 100000 - num[3] * 10000 - num[4] * 1000 - num[5] * 100) / 10;
		num[7] = (tot - num[0] * 10000000 - num[1] * 1000000 - num[2] * 100000 - num[3] * 10000 - num[4] * 1000 - num[5] * 100 - num[6] * 10) / 1;
	} else {
		much = 7;
		num[0] = tot / 1000000;
		num[1] = (tot - num[0] * 1000000) / 100000;
		num[2] = (tot - num[0] * 1000000 - num[1] * 100000) / 10000;
		num[3] = (tot - num[0] * 1000000 - num[1] * 100000 - num[2] * 10000) / 1000;
		num[4] = (tot - num[0] * 1000000 - num[1] * 100000 - num[2] * 10000 - num[3] * 1000) / 100;
		num[5] = (tot - num[0] * 1000000 - num[1] * 100000 - num[2] * 10000 - num[3] * 1000 - num[4] * 100) / 10;
		num[6] = (tot - num[0] * 1000000 - num[1] * 100000 - num[2] * 10000 - num[3] * 1000 - num[4] * 100 - num[5] * 10) / 1;
	}
	for (int i = 0; i < much; i++) {
		if (num[i] == 0) {
			table[0]++;
		} else if (num[i] == 1) {
			table[1]++;
		} else if (num[i] == 2) {
			table[2]++;
		} else if (num[i] == 3) {
			table[3]++;
		} else if (num[i] == 4) {
			table[4]++;
		} else if (num[i] == 5) {
			table[5]++;
		} else if (num[i] == 6) {
			table[6]++;
		} else if (num[i] == 7) {
			table[7]++;
		} else if (num[i] == 8) {
			table[8]++;
		} else {
			table[9]++;
		}
	}
	for (int i = 0; i <= much + 1; i++) {
		printf("%d\n", table[i]);
	}
	return 0;
}
