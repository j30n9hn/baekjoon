#include <stdio.h>

int main() {
	int num1, num2;
	int rnum1, rnum2;
	scanf("%d %d", &num1, &num2);

	rnum1 = num1 / 100;
	num1 = num1 - (num1 / 100) * 100;
	rnum1 = rnum1 + (num1 / 10) * 10;
	num1 = num1 - (num1 / 10) * 10;
	rnum1 = rnum1 + num1 * 100;

	rnum2 = num2 / 100;
	num2 = num2 - (num2 / 100) * 100;
	rnum2 = rnum2 + (num2 / 10) * 10;
	num2 = num2 - (num2 / 10) * 10;
	rnum2 = rnum2 + num2 * 100;
	
	if (rnum1 > rnum2) {
		printf("%d", rnum1);
	} else {
		printf("%d", rnum2);
	}
	return 0;
}
