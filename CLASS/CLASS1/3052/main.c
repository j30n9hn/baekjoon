#include <stdio.h>

int main() {
	int num[10];
	int mod[10];
	int cnt = 0;
	int temp;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 10; i++) {
		mod[i] = num[i] % 42;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mod[i] < mod[j]) {
				temp = mod[j];
				mod[j] = mod[i];
				mod[i] = temp;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		if (mod[i] != mod[i - 1]) {
			cnt++;
		}
	}
	printf("%d", cnt + 1);
	return 0;
}

