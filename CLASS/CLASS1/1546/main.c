#include <stdio.h>

int main() {
	int cnt;
	int max = 0;
	int pos;
	double total;
	double mean;

	scanf("%d", &cnt);

	int grade[cnt];
	double newgrade[cnt];

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &grade[i]);
	}
	for (int i = 0; i < cnt; i++) {
		if (max < grade[i]) {
			max = grade[i];
		}
	}
	for (int i = 0; i < cnt; i++) {
		newgrade[i] = (double) grade[i] / max * 100;
	}
	for (int i = 0; i < cnt; i++) {
		total += newgrade[i];
	}
	mean = total / cnt;
	printf("%lf", mean);
	return 0;
}
