#include <stdio.h>
#include <stdlib.h>
//n[a][b] == n[a - 1][b] + n[a][b - 1]

int main() {
	int tcase;
	int floor, room;

	scanf("%d", &tcase);

	for (int i = 0; i < tcase; i++) {
		int cntone[14] = { 0 };
		int cnttwo[14] = { 0 };
		scanf("%d\n%d", &floor, &room);
		for (int j = 0; j < floor; j++) {
			for (int k = 0; k < room; k++) {
				
	}
	

	return 0;
}
