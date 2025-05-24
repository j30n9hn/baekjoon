#include<stdio.h>
#include<stdlib.h>

int main() {
    char** frame;
    int row, col;
    int min = 64;
    int tmp = 0;
    int wc = 0;
    int bc = 0;

    scanf("%d %d", &row, &col);

    frame = (char**)malloc(sizeof(char*) * row);
    for (int i = 0; i < row; i++) {
        frame[i] = (char*)malloc(sizeof(char) * col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf(" %c", &frame[i][j]);
        }
    }

    for (int i = 0; i < row - 7; i++) {
        for (int j = 0; j < col - 7; j ++) {
            wc = 0;
            bc = 0;
            for (int fr = i; fr < i + 8; fr++) {
                for (int fc = j; fc < j + 8; fc++) {
                    if ((fr + fc) % 2 == 0) {
                        if (frame[fr][fc] != 'W') {
                            wc++;
                        }
                        if (frame[fr][fc] != 'B') {
                            bc++;
                        }
                    } else {
                        if (frame[fr][fc] != 'B') {
                            wc++;
                        }
                        if (frame[fr][fc] != 'W') {
                            bc++;
                        }
                    }
                }
            }
            tmp = wc < bc ? wc : bc;
            if ( min > tmp) {
                min = tmp;
            }
        }
    }

    printf("%d\n", min);

    for (int i = 0; i < row; i++) {
        free(frame[i]);
        frame[i] = NULL;
    }
    free(frame);
    frame = NULL;


    return 0;
}