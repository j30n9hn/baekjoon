#include <stdio.h>
#include <stdlib.h>

int squ(int i) {
	int r = 1;
	if (i == 0) {
		return 1;
	} else {
		for (int j = 0; j < i; j++) {
			r *= 31;
		}
		return r;
	}
}

int main() {
	int l;
	int alp[26] = { 0 };
	int sig = 0;
	int m = 1234567891;

	scanf("%d", &l);

	char* str = (char*)malloc(sizeof(char) * (l + 1));

	scanf("%s", str);
	for (int i = 0; i < 26; i++) {
		alp[i] = i + 1;
	}
	for (int i = 0; i < l; i++) {
		sig += alp[str[i] - 97] * squ(i);
	}
	sig %= m;
	printf("%d", sig);
	free(str);
	return 0;
}

	//(9*(31^x))%1234567891
