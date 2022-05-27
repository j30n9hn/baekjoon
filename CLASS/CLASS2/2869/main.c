#include <stdio.h>

int main() {
	int fw, re, hei;
	int temp;

	scanf("%d %d %d", &fw, &re, &hei);
	if (fw > hei) {
		printf("1");
	} else if (fw == hei) {
		printf("2");
	} else {
		temp = fw - re;
		

