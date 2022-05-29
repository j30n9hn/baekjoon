#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//n[a][b] == n[a - 1][b] + n[a][b - 1]

int main() {
	int tcase;

	scanf("%d", &tcase);
	
	int *sol = (int*)malloc(sizeof(int) * tcase);
	int *floor = (int*)malloc(sizeof(int) * tcase);
	int *room = (int*)malloc(sizeof(int) * tcase);

	for (int i = 0; i < tcase; i++) {
		scanf("%d\n%d", &floor[i], &room[i]);
	}

	for (int i = 0; i < tcase; i++) {
		int cntone[14] = { 0 };
		int cnttwo[14] = { 0 };
		
		for (int j = 0; j < 14; j++) {
			cntone[j] = j + 1;
		}
		cnttwo[0] = 1;
		for (int j = 0; j < floor[i]; j++) {
			for (int k = 1; k < room[i]; k++) {
				cnttwo[0] = 1;
				cnttwo[k] = cnttwo[k - 1] + cntone[k];
			}
			memcpy(cntone, cnttwo, sizeof(cnttwo));
		}
		sol[i] = cnttwo[room[i] - 1];
	}

	for (int i = 0; i < tcase; i++) {
		printf("%d\n", sol[i]);
	}
	free(sol);
	free(floor);
	free(room);

	return 0;
}
