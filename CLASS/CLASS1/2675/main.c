#include <stdio.h>
#include <string.h>

int main() {
	int tnumber;
	int len;

	scanf("%d", &tnumber);
	
	int tcase[tnumber];
	char str[tnumber][21];

	for (int i = 0; i < tnumber; i++) {
		scanf("%d %s", &tcase[i], str[i]);
	}//입력
	for (int i = 0; i < tnumber; i++) {//전체 테스트 케이스 실행
		len = strlen(str[i]);
		for (int j = 0; j <	len; j++) {
			for (int k = 0; k < tcase[i]; k++) {
				if (str[i][j] == 0x5c) {
					printf("\\");
				}
				printf("%c", str[i][j]);
			}
		}
		printf("\n");
	}



	return 0;
}
