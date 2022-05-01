#include <stdio.h>

int main() {
	int numlen;
	int total = 0;

	scanf("%d", &numlen);
	
	char str[numlen];
	int num[numlen];

	scanf("%s", str);
	for (int i = 0; i < numlen; i++) {
		for (int j = 48; j <= 57; j++) {
			if (str[i] == j) {
				num[i] = j - 48;
			}
		}
	}
	for (int i = 0; i < numlen; i++) {
		total += num[i];
	}
	printf("%d", total);
	return 0;
}
