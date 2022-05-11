#include <stdio.h>
#include <string.h>

int main() {
	char num[6];
	int len = 0;
	int cnt[100] = { 0 };
	int i;

	for (i = 0; ; i++) {
		scanf("%s", num);
		if (num[0] == '0') {
			break;
		}
		len = strlen(num);
		if (len == 1) {
			cnt[i] = 1;
		} else if (len == 2) {
			if (num[0] == num[1]) {
				cnt[i] = 1;
			}
		} else if (len == 3) {
			if (num[0] == num[2]) {
				cnt[i] = 1;
			}
		} else if (len == 4) {
			if ((num[0] == num[3]) && (num[1] == num[2])) {
				cnt[i] = 1;
			}
		} else {
			if ((num[0] == num[4]) && (num[1] == num[3])) {
				cnt[i] = 1;
			}
		}
	}
	for (int j = 0; j < i; j++) {
		if (cnt[j] == 1) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}
