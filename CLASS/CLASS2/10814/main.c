#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int index;
    int age;
    char name[101];
} User;

int compare( const void* arg1, const void* arg2);

int main() {
    int cnt;
    User* user;

    scanf("%d", &cnt);
    user = (User*)malloc(sizeof(User) * cnt);
    for (int i = 0; i < cnt; i++) {
        user[i].index = i;
        scanf("%d %s", &user[i].age, user[i].name);
    }
    qsort(user, cnt, sizeof(User), compare);

    for (int i = 0; i < cnt; i++) {
        printf("%d %s\n", user[i].age, user[i].name);
    }
    free(user);
    user = NULL;

    return 0;
}

int compare( const void* arg1, const void* arg2) {
    if (((User*)arg1)->age != ((User*)arg2)->age)
        return (((User*)arg1)->age - ((User*)arg2)->age);
    else
        return (((User*)arg1)->index - ((User*)arg2)->index);
}
