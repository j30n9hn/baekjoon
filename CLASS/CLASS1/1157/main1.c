#include <stdio.h>
#include <string.h>

char str[1000001];

int main() {
	int cnt[26] = { 0 };	
	int len;
	int max = 0;
	int pos = 0;
	int cmp = 0;

	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++) {	
		if (str[i] <= 90) {
			cnt[str[i] - 65]++;
		}
	}
	for (int i = 0; i < len; i++) {
		if (str[i] > 90) {
			cnt[str[i] - 97]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			pos = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if ((cnt[i] == max) && (i != pos) && (len != 1)) {
			printf("?");
			return 0;
		}
	}
	printf("%c", pos + 65);
	return 0;
}
		
