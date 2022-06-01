#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int height = 6, width = 8;
int **arr;
arr = (int**) malloc ( sizeof(int*) * height );
for(int i=0; i<height; i++){
    arr[i] = (int*) malloc ( sizeof(int) * width );
}
*/
/*
for(int i=0; i<height; i++){
    free(arr[i]);
}
free(arr);
*/

int main() {
	int cnt;
	int min;

	scanf("%d", &cnt);
	
	char **voca = (char**)malloc(sizeof(char) * cnt);
	int *len = (int*)malloc(sizeof(int) * cnt);

	for (int i = 0; i < cnt; i++) {
		voca[i] = (char*)malloc(sizeof(char) * 51);
	}
	for (int i = 0; i < cnt; i++) {
		scanf("%s", voca[i]);
	}
	for (int i = 0; i < cnt; i++) {
		len[i] = strlen(voca[i]);
	}
	for (int i = 1; i <= cnt; i++) {



	

	return 0;
}
