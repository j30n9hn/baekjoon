#include <stdio.h>

int main() {
	int scale[8];
	int out;

	for (int i = 0; i < 8; i++) {
		scanf("%d" ,&scale[i]);
	}
	for (int i = 1; i < 8; i ++) {
		if (scale[i] == scale[i - 1] + 1) {
			out = 0;
			continue;
		} else if (scale[i] == scale[i - 1] - 1) {
			out = 1;
			continue;
		} else {
			out = 2;
			break;
		}
	}
	if (out == 0) {
		printf("ascending");
	} else if (out == 1) {
		printf("descending");
	} else {
		printf("mixed");
	}
	return 0;
}
