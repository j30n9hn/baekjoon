/*
*  Description: DFS, BFS
*/
#include <stdio.h>
#include <stdlib.h>

void addEdge(int** adj, int vertex, int neighborVertex);
void callDFS(int** adj, int* resultDFS, int* resultIndex, int numVertex, int startVertex);
void DFS(int** adj, int src, int* visited, int* resultDFS, int* resultIndex, int numVertex);
void callBFS(int** adj, int* resultBFS, int* resultIndex, int numVertex, int startVertex);
void BFS(int** adj, int src, int* visited, int* resultBFS, int* resultIndex, int numVertex);

int main() {
    // declarePhase
    int numVertex, numEdge, startVertex;
    int** adj;
    int vertex, neighborVertex;
    int *resultDFS, *resultBFS;
    int resultIndex = 0;

    // initializePhase
    scanf("%d %d %d", &numVertex, &numEdge, &startVertex);
    startVertex--;
    resultDFS = (int*)calloc(numVertex, sizeof(int));
    resultBFS = (int*)calloc(numVertex, sizeof(int));
    adj = (int**)calloc(numVertex, sizeof(int*));
    for (int i = 0; i < numVertex; i++)
        adj[i] = (int*)calloc(numVertex, sizeof(int));

    for (int i = 0; i < numEdge; i++) {
        scanf("%d %d", &vertex, &neighborVertex);
        vertex--;
        neighborVertex--;
        addEdge(adj, vertex, neighborVertex);
    }

    // dfsPhase
    callDFS(adj, resultDFS, &resultIndex, numVertex, startVertex);
    for (int i = 0; i < resultIndex; i++) printf("%d ", resultDFS[i] + 1);
    resultIndex = 0;
    printf("\n");

    // bfsPhase
    callBFS(adj, resultBFS, &resultIndex, numVertex, startVertex);
    for (int i = 0; i < resultIndex; i++) printf("%d ", resultBFS[i] + 1);

    //freePhase
    for (int i = 0; i < numVertex; i++) {
        free(adj[i]);
        adj[i] = NULL;
    }
    free(adj);
    adj = NULL;
    free(resultBFS);
    resultBFS = NULL;
    free(resultDFS);
    resultDFS = NULL;
    
    return 0;
}

void addEdge(int** adj, int vertex, int neighborVertex) {
    adj[vertex][neighborVertex] = 1;
    adj[neighborVertex][vertex] = 1;
}

void callDFS(int** adj, int* resultDFS, int* resultIndex, int numVertex, int startVertex) {
    int* visited = (int*)calloc(numVertex, sizeof(int));
    DFS(adj, startVertex, visited, resultDFS, resultIndex, numVertex);

//    for (int i = 0; i < numVertex; i++) if (!visited[i]) DFS(adj, i, visited, resultDFS, resultIndex, numVertex);

    free(visited);
    visited = NULL;
}

void DFS(int** adj, int src, int* visited, int* resultDFS, int* resultIndex, int numVertex) {
    visited[src] = 1;
    resultDFS[(*resultIndex)++] = src;

    for (int i = 0; i < numVertex; i++) if (adj[src][i] && !visited[i]) DFS(adj, i, visited, resultDFS, resultIndex, numVertex);
}

void callBFS(int** adj, int* resultBFS, int* resultIndex, int numVertex, int startVertex) {
    int* visited = (int*)calloc(numVertex, sizeof(int));
    BFS(adj, startVertex, visited, resultBFS, resultIndex, numVertex);

//    for (int i = 0; i < numVertex; i++) if (!visited[i]) BFS(adj, i, visited, resultBFS, resultIndex, numVertex);

    free(visited);
    visited = NULL;
}

void BFS(int** adj, int src, int* visited, int* resultBFS, int* resultIndex, int numVertex) {
    int* queue = (int*)calloc(numVertex, sizeof(int));
    int front = 0;
    int rear = 0;
    int vertex;

    visited[src] = 1;
    queue[rear++] = src;

    while (front < rear) {
        vertex = queue[front++];
        resultBFS[(*resultIndex)++] = vertex;

        for (int i = 0; i < numVertex; i++) {
            if (adj[vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    free(queue);
    queue = NULL;
}
