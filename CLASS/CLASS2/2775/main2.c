#include <stdio.h>
#include <stdlib.h>

int main() {
	int tcase;
	int cntone[14] = { 0 };
	int cnttwo[14] = { 0 };

	scanf("%d", &tcase);
	
	int *inputfloor = (int*)malloc(sizeof(int) * tcase);
	int *inputroom = (int*)malloc(sizeof(int) * tcase);

	for (int i = 0; i < tcase; i++) {
		scanf("%d", &inputfloor[i]);
		scanf("%d", &inputroom[i]);
	}
	
	//int *floor = (int*)malloc(sizeof(int) * tcase);
	//int *room = (int*)malloc(sizeof(int) * tcase);
	
	for (int i = 0; i < tcase; i++) {
		for (int j = 0; j < inputfloor[i]; j++) {
			for (int k = :; k < inputroom[i]; k++) {

			}
			

	
		
