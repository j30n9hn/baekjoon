#include <stdio.h>
#include <string.h>

int main() {
	int a;
	char len;
	char exch;

	scanf("%d", &a);
	exch = (char)a;
	len = strlen(exch);
	printf("%d", a);
	return 0;
}
