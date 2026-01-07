#include <stdio.h>
#include <stdlib.h>

int isValid(int* grid, int* visited, int row, int col, int maxRow, int maxCol);
void BFS(int* grid, int* visited, int startRow, int startCol, int row, int col);

int main() {
    int tCase;
    int node;
    int row, col;
    int earthworm;
    int* grid;
    int* visited;
    int floorN, indexN;

    scanf("%d", &tCase);

    while (tCase > 0) {
        earthworm = 0;
        scanf("%d %d %d", &row, &col, &node);
        grid = (int*)calloc(row * col, sizeof(int));
        visited = (int*)calloc(row * col, sizeof(int));

        for (int i = 0; i < node; i++) {
            scanf("%d %d", &floorN, &indexN);
            grid[floorN * col + indexN] = 1;
        }

/*
        for (int floor = 0; floor < row; floor++) {
            for (int index = 0; index < col; index++) {
                printf("%d ", grid[floor * col + index]);
            }
            printf("\n");
        }

        printf("BFS start\n");
*/
        for (int floor = 0; floor < row; floor++) {
            for (int index = 0; index < col; index++) {
                if (grid[floor * col + index] == 1 && !visited[floor * col + index]) {
                    earthworm++;
                    BFS(grid, visited, floor, index, row, col);
                }
            }
        }

        printf("%d\n", earthworm);

        free(grid);
        free(visited);
        tCase--;
    }


    return 0;
}

int isValid(int* grid, int* visited, int row, int col, int maxRow, int maxCol) {
    if (row < 0 || col < 0 || row >= maxRow || col >= maxCol) return 0;
    if (visited[row * maxCol + col]) return 0;
    if (!grid[row * maxCol + col]) return 0;
    return 1;
}

void BFS(int* grid, int* visited, int startRow, int startCol, int row, int col) {
    int maxSize = row * col;
    int front = 0;
    int rear = 0;
    int* qx = (int*)calloc(maxSize, sizeof(int));
    int* qy = (int*)calloc(maxSize, sizeof(int));
    int x, y;
    int nx, ny;
    int dir;

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    qx[rear] = startRow;
    qy[rear] = startCol;
    rear++;

    visited[startRow * col + startCol] = 1;

    while(front < rear) {
        x = qx[front];
        y = qy[front];
        front++;

        for (dir = 0; dir < 4; dir++) {
            nx = x + dRow[dir];
            ny = y + dCol[dir];

            if (isValid(grid, visited, nx, ny, row, col)) {
                visited[nx * col + ny] = 1;
                qx[rear] = nx;
                qy[rear] = ny;
                rear++;
            }
        }
    }
    free(qx);
    free(qy);
}
