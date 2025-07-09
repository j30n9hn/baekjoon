/*
 * Description: Dynamic Programming (Bottom-Up), Math (Recurrence relation)
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int* floor;
    int* score;
} stairs;

void initStairs(stairs* s, int theNumberOfFloor);
void freeStairs(stairs* s);
int getMaximum(stairs* s, int theNumberOfFloor);


int main() {
    int theNumberOfFloor;
    stairs s;

    scanf("%d", &theNumberOfFloor);
    initStairs(&s, theNumberOfFloor);

    for (int i = 1; i <= theNumberOfFloor; i++) {
        scanf("%d", &s.floor[i]);
    }

    printf("%d\n", getMaximum(&s, theNumberOfFloor));

    freeStairs(&s);
    return 0;
}

void initStairs(stairs* s, int theNumberOfFloor) {
    s->floor = (int*)malloc(sizeof(int) * (theNumberOfFloor + 1));
    s->score = (int*)malloc(sizeof(int) * (theNumberOfFloor + 1));
}

void freeStairs(stairs* s) {
    free(s->floor);
    s->floor = NULL;
    free(s->score);
    s->score = NULL;
}

int getMaximum(stairs* s, int theNumberOfFloor) {
    if (theNumberOfFloor == 1) return s->floor[1];
    if (theNumberOfFloor == 2) return s->floor[1] + s->floor[2];

    s->score[1] = s->floor[1];
    s->score[2] = s->floor[1] + s->floor[2];
    s->score[3] = MAX(s->floor[1] + s->floor[3], s->floor[2] + s->floor[3]);

    for (int i = 4; i <= theNumberOfFloor; i++) {
       s->score[i] = MAX(s->score[i - 3] + s->floor[i - 1] + s->floor[i], s->score[i - 2] + s->floor[i]);
    }
    return s->score[theNumberOfFloor];
}