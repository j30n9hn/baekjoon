#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parlin(char num[6]) {
  int len = strlen(num);
  char rnum[6];
  int pos = 0;

  for (int i = len - 1; i >= 0; i--) {
    rnum[pos] = num[i];
    pos++;
  }
  return strcmp(num, rnum);
}

int main() {
  int tcase = 0;
	char num[6];
	int* sol = (int*)malloc(sizeof(int) * 1);

	for (int i = 0; ; i++) {
		scanf("%s", num);
    if (num[0] == 48) {
      break;
    }
    tcase++;
    sol[i] = parlin(num);
    sol = (int*)realloc(sol, sizeof(int) * 1);
  }
  for (int i = 0; i < tcase; i++) {
    if (sol[i] == 0) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  free(sol);
  return 0;
} 
