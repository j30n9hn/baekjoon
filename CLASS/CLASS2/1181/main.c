#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare( const void *arg1, const void *arg2 );

int main() {
	int cnt;
	int min;
	int arg1Len = 0;
	int arg2Len = 0;
	char *tmp;

	scanf("%d", &cnt);

	char **voca = (char**)malloc(sizeof(char *) * cnt);
	for (int i = 0; i < cnt; i++) {
		voca[i] = (char*)malloc(sizeof(char) * 51);
		scanf("%50s", voca[i]);
	}
	qsort( (void *) voca, cnt, sizeof( char * ), compare);
	/*
	base => Start of target array
	number => Array size in elements
	width => element size in bytes
	compare => pointer to a user-supplied routine
	*/

	printf("%s\n", voca[0]); // 첫 번째 단어는 무조건 출력
    for (int i = 1; i < cnt; i++) {
        if (strcmp(voca[i], voca[i - 1]) != 0) printf("%s\n", voca[i]);
    }
	


	for (int i = 0; i < cnt; i++) {
		voca[i] = NULL;
    	free(voca[i]);
	}

	voca = NULL;
	free(voca);

	return 0;
}

int compare( const void *arg1, const void *arg2 ) {
	/*
	arg1 < arg2 => return < 0
	arg1 == arg2 => return = 0
	arg1 > arg2 => return > 0
	*/

	if (strlen(* ( char** ) arg1) > strlen(* ( char**) arg2)) return 1;
	else if (strlen(* ( char** ) arg1) < strlen(* ( char**) arg2)) return -1;
	else return strcmp( * ( char** ) arg1, * ( char**) arg2 );
}