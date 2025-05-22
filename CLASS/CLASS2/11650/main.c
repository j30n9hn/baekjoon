#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int compare( const void* arg1, const void* arg2);

int main() {
    int cnt;
    Point* point;

    scanf("%d", &cnt);
    point = (Point*)malloc(sizeof(Point) * cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d %d", &point[i].x, &point[i].y);
    }
    qsort(point, cnt, sizeof(Point), compare);

    for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", point[i].x, point[i].y);
    }
    free(point);
    point = NULL;

    return 0;
}

int compare( const void* arg1, const void* arg2) {
    if (((Point*)arg1)->x != ((Point*)arg2)->x)
        return (((Point*)arg1)->x - ((Point*)arg2)->x);
    else
        return (((Point*)arg1)->y - ((Point*)arg2)->y);
}
