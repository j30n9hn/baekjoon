/*
 * Description: Set and bitmask 
 */
#include<stdio.h>
#include<string.h>

void add(int* set, int num);
void removef(int* set, int num);
int check(int* set, int num);
void toggle(int* set, int num);
void all(int* set);
void empty(int* set);

int main() {
    char command[6];
    int set[21] = { 0 };
    int loop;
    int num;

    scanf("%d", &loop);

    for (int i = 0; i < loop; i++) {
        scanf("%s", command);
        if (strstr(command, "all") != NULL) {
            all(set);
        } else if (strstr(command, "empty") != NULL) {
            empty(set);
        } else if (strstr(command, "add") != NULL) {
            scanf("%d", &num);
            add(set, num);
        } else if (strstr(command, "remove") != NULL) {
            scanf("%d", &num);
            removef(set, num);
        } else if (strstr(command, "check") != NULL) {
            scanf("%d", &num);
            printf("%d\n", check(set, num));
        } else {
            scanf("%d", &num);
            toggle(set, num);
        }
    }

    return 0;
}

void add(int* set, int num) {
    if (set[num] == 0) {
        set[num] = 1;
    }
}

void removef(int* set, int num) {
    if (set[num] == 1) {
        set[num] = 0;
    }
}

int check(int* set, int num) {
    return set[num];
}

void toggle(int* set, int num) {
    if (set[num] == 1) {
        set[num] = 0;
    } else {
        set[num] = 1;
    }
}

void all(int* set) {
    for (int i = 0; i < 21; i++) {
        set[i] = 1;
    }
}

void empty(int* set) {
    for (int i = 0; i < 21; i++) {
        set[i] = 0;
    }
}