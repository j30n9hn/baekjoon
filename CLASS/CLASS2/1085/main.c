#include <stdio.h>

int main() {
	int x, y, w, h;
	int disx, disy;
	int mx, my;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	disx = w - x;
	disy = h - y;
	if (disx <= x) {
		mx = disx;
	} else {
		mx = x;
	}
	if (disy <= y) {
		my = disy;
	} else {
		my = y;
	}
	if (mx <= my) {
		printf("%d", mx);
	} else {
		printf("%d", my);
	}
	
	return 0;
}
