#include <stdio.h>
#include <string.h>

#define MAX 1000000

char str[MAX + 1];
int main() {
	int len;
	int cnt[len + 1];
	int acc = 0;
	int max = 0;
	int pos = 0;
	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (str[i] == (str[j] || str[i] + 32 || str[i] - 32)) {
				acc++;
			}
		}
		cnt[i] = acc;
		acc = 0;
	}
	for (int i = 0; i < len; i++) {
		if (max <= cnt[i]) {
			max = cnt[i];
			pos = i;
		}
	}
	for (int a = 0; a < len; a++) {
		for (int b = 0; b < len; b++) {
			if ((cnt[a] == max) && (str[a] != str[b])) {
				printf("?");
				return 0;
			}
		}
	}
	if (str[pos] <= 90) {
		printf("%c", str[pos]);
	}
	else {
		printf("%c", str[pos] - 32);
	}
	return 0;
}
