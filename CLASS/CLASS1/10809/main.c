#include <stdio.h>
#include <string.h>

int main() {
	char str[101];
	int len;
	int alp[26];

	for (int i = 0; i < 26; i++) {
		alp[i] = -1;
	}
	scanf("%s", str);
	len = strlen(str);
	
	for (int i = 0; i <= len; i++) {
		for (int j = 97; j < 123; j++) {
			if(str[i] == j) {
				if(alp[j - 97] != -1) {
				continue;
				}
				alp[j - 97] = i;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alp[i]);
	}

	return 0;
}
