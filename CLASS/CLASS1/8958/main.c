#include <stdio.h>
#include <string.h>

int main() {
	int tcase;
	int add = 0;

	scanf("%d", &tcase);

	char sol[tcase][81];
	int len[tcase];
	int tot[tcase];

	for (int i = 0; i < tcase; i++) {
		scanf("%s", sol[i]);
		len[i] = strlen(sol[i]);
	}
	for (int i = 0; i < tcase; i++) {
		for (int j = 0; j < len[i]; j++) {
			if (sol[i][j] == 0x4f) {
				add++;
				tot[i] += add;
			} else {
				add = 0;
			}
		}
		add = 0;
	}
	for (int i = 0; i < tcase; i++) {
		printf("%d\n", tot[i]);
	}
	return 0;
}
