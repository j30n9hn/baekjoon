#include <stdio.h>
#include <string.h>

#define MAX 1000000

char str[MAX + 1];

int main() {
	int len;
	int cnt = 0;

	fgets(str, sizeof(str), stdin);	
	len = strlen(str);
	if (len == 1) {
		printf("%d", 0);
		return 0;
	}
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			cnt++;
		}
	}
	if (str[0] == ' ') {
		cnt -= 1;
	}
	if (str[len - 2] == ' ') {
		cnt -= 1;
	}

	printf("%d", cnt + 1);

	return 0;
}


