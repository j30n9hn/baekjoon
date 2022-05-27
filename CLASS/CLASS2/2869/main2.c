#include <stdio.h>

int main() {
	int fw, re, hei;
	double temp;

	scanf("%d %d %d", &fw, &re, &hei);
	
	temp = (double)(hei - re) / (fw - re);
	if (temp > (int)temp) {
		printf("%d", (int)temp + 1);
	} else {
		printf("%d", (int)temp);
	}
	return 0;
}
