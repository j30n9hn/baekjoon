#include <stdio.h>

int main() {
	int num1, num2;
	int a, b, c;

	scanf("%d %d", &num1, &num2);
	a = (num2 / 100) * 100;
	b = ((num2 - a) / 10) * 10;
	c = (num2 - a - b) / 1;
	printf("%d\n%d\n%d\n%d", num1 * c, num1 * b, num1 * a, num1 * num2);
	
	return 0;
}
