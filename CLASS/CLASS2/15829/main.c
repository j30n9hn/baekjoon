#include <stdio.h>
#include <stdlib.h>

int main() {
	int l;
	int alp[26] = { 0 };
	int sig = 0;
	int r = 31;
	int m = 1234567891;

	scanf("%d", &l);

	char* str = (char*)malloc(sizeof(char) * (l + 1));

	for (int i = 0; i < l; i++) {
		scanf("%s", str);
	}
	for (int i = 0; i < 26; i++) {
		alp[i] = i + 1;
	}
	for (int i = 0; i < l; i++) {
		sig += alp[str[i] - 26] * (double) pow((double)r, (double)i);
	}


	//(9*(31^x))%1234567891
