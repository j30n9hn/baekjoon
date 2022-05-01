#include <stdio.h>

int main() {
	int fir, sec, thi;
	int tot;
	int cnt[10] = { 0 };
	int pos = 0;
	int num[9] = { 0 };
	int i = 0;

	scanf("%d %d %d", &fir, &sec, &thi);
	tot = fir * sec * thi;
	if (tot >= 100000000) {
		for (i = 100000000; i >= 1; ) {
			num[pos] = tot / i;
			tot = tot - num[pos] * i;
			pos++;
			i /= 10;
		}
	} else if (tot >= 10000000) {
		for (i = 10000000; i >= 1; ) {
			num[pos] = tot / i;
			tot = tot - num[pos] * i;
			pos++;
			i /= 10;
		}
	} else {
		for (i = 1000000; i >= 1; ) {
			num[pos] = tot / i;
			tot = tot - num[pos] * i;
			pos++;
			i /= 10;
		}
	}
	tot = fir * sec * thi;
	if (tot >= 100000000) {
		for (i = 0; i <= 8; i++) {
			if (num[i] == 0) {
				cnt[0]++;
			} else if (num[i] == 1) {
				cnt[1]++;
			} else if (num[i] == 2) {
				cnt[2]++;
			} else if (num[i] == 3) {
				cnt[3]++;
			} else if (num[i] == 4) {
				cnt[4]++;
			} else if (num[i] == 5) {
				cnt[5]++;
			} else if (num[i] == 6) {
				cnt[6]++;
			} else if (num[i] == 7) {
				cnt[7]++;
			} else if (num[i] == 8) {
				cnt[8]++;
			} else {
				cnt[9]++;
			}
		}
	} else if (tot >= 10000000) {
		for (i = 0; i <= 7; i++) {
			if (num[i] == 0) {
				cnt[0]++;
			} else if (num[i] == 1) {
				cnt[1]++;
			} else if (num[i] == 2) {
				cnt[2]++;
			} else if (num[i] == 3) {
				cnt[3]++;
			} else if (num[i] == 4) {
				cnt[4]++;
			} else if (num[i] == 5) {
				cnt[5]++;
			} else if (num[i] == 6) {
				cnt[6]++;
			} else if (num[i] == 7) {
				cnt[7]++;
			} else if (num[i] == 8) {
				cnt[8]++;
			} else {
				cnt[9]++;
			}
		}
	} else {
		for (i = 0; i <= 6; i++) {
			if (num[i] == 0) {
				cnt[0]++;
			} else if (num[i] == 1) {
				cnt[1]++;
			} else if (num[i] == 2) {
				cnt[2]++;
			} else if (num[i] == 3) {
				cnt[3]++;
			} else if (num[i] == 4) {
				cnt[4]++;
			} else if (num[i] == 5) {
				cnt[5]++;
			} else if (num[i] == 6) {
				cnt[6]++;
			} else if (num[i] == 7) {
				cnt[7]++;
			} else if (num[i] == 8) {
				cnt[8]++;
			} else {
				cnt[9]++;
			}
		}
	}
	for (i = 0; i <= 9; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}
