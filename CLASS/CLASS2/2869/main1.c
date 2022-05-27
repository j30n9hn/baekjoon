#include <stdio.h>

int main() {
	int fw, re, hei;
	int day = 1;

	scanf("%d %d %d", &fw, &re, &hei);
	for (int i = fw; ; i += fw) {
		if (i >= hei) {
			printf("%d", day);
			break;
		}
		day++;
		i -= re;
	}



	return 0;
}
/*if a > v
1 day
else if a == v
2 day
else if
c = a-b
c + a >= v
alpha | +1 day*/
