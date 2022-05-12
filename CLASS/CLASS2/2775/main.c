#include <stdio.h>
#include <stdlib.h>
//n[a][b] == n[a - 1][b] + n[a][b - 1]

int howmanypp (int floor, int room) {

	return 0;
}


int main() {
	int tcase;
	int floor, room;

	scanf("%d", &tcase);

	int* how = (int*)malloc(sizeof(int) * tcase);
	for (int i = 0; i < tcase; i++) {
		scanf("%d\n%d", &floor, &room);
	}
	

	return 0;
}
