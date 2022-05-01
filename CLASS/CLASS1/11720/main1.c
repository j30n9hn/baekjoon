#include <stdio.h>

int main() {
	int numlen;
	int ten = 10;
	int num;
	int pos = 0;
	int total = 0;

	scanf("%d", &numlen);
	scanf("%d", &num);

	int divnum[numlen];

	if (numlen == 1) {
		ten = ten / 10;
	} else {
		for (int i = numlen - 1; i > 1; i--) {
			ten = ten * 10;
		}
	}
	for (int i = ten; i >= 1; i = i / 10) {
		if (num >= ten) {
			divnum[pos] = num / i;
			num = (num - (num / i) * i);
			pos++;
		} else {
			divnum[pos] = 0;
			pos++;
			continue;
		}
	}
	for(int i = 0; i < numlen; i++) {
		total = total + divnum[i];
	}
	printf("%d", total);

	return 0;
}
