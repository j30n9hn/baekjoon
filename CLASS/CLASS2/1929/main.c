/*
 * Description: Math Implementation (sieve of Eratosthenes)
 */
#include<stdio.h>
#include<stdlib.h>

int main() {
	int num1, num2;
	int* arr;

	scanf("%d %d", &num1, &num2);
	arr = (int*)malloc(sizeof(int) * (num2 + 1));

	for (int i = 0; i <= num2; i++) {
		arr[i] = i;
	}
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= num2; i++) {
		for (int j = 2 * i; j <= num2; j += i) {
			if (arr[j] == 0) continue;
			arr[j] = 0;
		}
	}

	for (int i = 0; i <= num2; i++) {
		if (arr[i] < num1) continue;
		if (arr[i] != 0 && arr[i] != 1) printf("%d\n", arr[i]);
		else continue;
	}


	free(arr);
	arr = NULL;

	return 0;
}
