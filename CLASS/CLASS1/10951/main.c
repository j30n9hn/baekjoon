#include <stdio.h>

int num[1000000];

int main() {
	int a, b;
	int cnt = 0;

	for (int i = 0; ; i++) {	
		if (scanf("%d %d", &a, &b) != EOF) {
			num[cnt] = a + b;
			cnt++;
		} else {
			for (int i =0; i < cnt; i++) {
				printf("%d\n", num[i]);
			}
			return 0;
		}		
	}
	return 0;
}
