/*
 * Description: Math Implementation
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(const void* arg1, const void* arg2);

int main() {
	int cnt;
	int mean;//15%
	float sum = 0;
	float total;
	int* appraisal;

	scanf("%d", &cnt);
	if (cnt == 0) {
		printf("0\n");
	} else {
		appraisal = (int*)malloc(sizeof(int) * cnt);
		mean = round(cnt * 0.15);
		total = cnt - mean * 2;

		for (int i = 0; i < cnt; i++) {
			scanf("%d", &appraisal[i]);
		}
		qsort(appraisal, cnt, sizeof(int), compare);

		for (int i = mean; i < cnt - mean; i++) {
			sum += appraisal[i];
		}
		printf("%d\n", (int)round(sum / total));	
	
		free(appraisal);
		appraisal = NULL;
	}

	return 0;
}

int compare(const void* arg1, const void* arg2) {
	const int num1 = *(int*)arg1;
	const int num2 = *(int*)arg2;
	int value = num1 - num2;

	if (value < 0) return -1;
	else if (value > 0) return 1;
	else return 0;
}
