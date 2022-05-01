#include <stdio.h>

int main() {
	int h, m;

	scanf("%d %d", &h, &m);
	if ((m - 45) < 0) {
		m = 60 - (45 - m);
		h--;
		if (h < 0) {
			h = 24 + h;
		}
		printf("%d %d", h, m);
	} else {
		printf("%d %d", h, m - 45);
	}
	return 0;
}
