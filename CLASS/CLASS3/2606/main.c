/*
 * Description: BFS, Circular Queue
 */
#include <stdio.h>
#include <stdlib.h>

// 각 노드는 구조체로 구성

typedef struct {
    int color; // 0: white, 1: gray, 2: black
    int* adj;
    int adjSize;
} node;

typedef struct {
    int size;
    int capacity;
    int front;
    int* arr;
} queue;


void initNode(node** n, int numberOfNodes);
void freeNode(node* n, int numberOfNodes);
void initQueue(queue* q, int numberOfNodes);
void freeQueue(queue* q);
void addEdge(node** n, int u, int v);
void enqueue(queue* q, int node);
int dequeue(queue* q);
int BFS(node** n, queue* q);

int main() {
    int numberOfNodes;
    int numberOfPairs;
    int node1, node2;
    node* n;
    queue q;

    scanf("%d", &numberOfNodes);
    scanf("%d", &numberOfPairs);

    initNode(&n, numberOfNodes);
    initQueue(&q, numberOfNodes);

    for (int i = 0; i < numberOfPairs; i++) {
        scanf("%d %d", &node1, &node2);
        addEdge(&n, node1, node2);
    }

    printf("%d\n", BFS(&n, &q));


    freeNode(n, numberOfNodes);
    freeQueue(&q);

    return 0;
}

void initNode(node** n, int numberOfNodes) {
    *n = (node*)malloc(sizeof(node) * (numberOfNodes + 1));
    for (int i = 1; i <= numberOfNodes; i++) {
        (*n)[i].color = 0;
        (*n)[i].adjSize = 0;
        (*n)[i].adj = (int*)malloc(sizeof(int) * (numberOfNodes + 1));
        for (int j = 1; j <= numberOfNodes; j++) {
            (*n)[i].adj[j] = -1;
        }
    }
    (*n)[1].color = 1;
}

void freeNode(node* n, int numberOfNodes) {
    for (int i = 1; i <= numberOfNodes; i++) {
        free(n[i].adj);
        n[i].adj = NULL;
    }
    free(n);
    n = NULL;
}

void initQueue(queue* q, int numberOfNodes) {
    q->capacity = numberOfNodes;
    q->front = 0;
    q->size = 0;
    q->arr = (int*)malloc(sizeof(int) * numberOfNodes);
    for (int i = 0; i < numberOfNodes; i++) {
        q->arr[i] = -1;
    }
}

void freeQueue(queue* q) {
    free(q->arr);
    q->arr = NULL;
}

void addEdge(node** n, int u, int v) {
    //(*n)[u].adj = realloc((*n)[u].adj, sizeof(int) * ((*n)[u].adjSize + 1));
    (*n)[u].adj[(*n)[u].adjSize++] = v;

    //(*n)[v].adj = realloc((*n)[v].adj, sizeof(int) * ((*n)[v].adjSize + 1));
    (*n)[v].adj[(*n)[v].adjSize++] = u;
}

void enqueue(queue* q, int node) {
    int rear;
    if (q->size == q->capacity) {
        return;
    } else {
        rear = (q->front + q->size) % q->capacity;
        q->arr[rear] = node;
        q->size++;
    }
}

int dequeue(queue* q) {
    int search;
    if (q->size == 0) {
        return -1;
    } else {
        search = q->arr[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
    return search;
}

int BFS(node** n, queue* q) {
    int cnt = 0;
    int current;
    int link;
    enqueue(q, 1);
    while (q->size > 0) {
        current = dequeue(q);

        for (int i = 0; i < (*n)[current].adjSize; i++) {
            link = (*n)[current].adj[i];

            if ((*n)[link].color == 0) {
                (*n)[link].color = 1;
                enqueue(q, link);
                cnt++;
            }
        }

        (*n)[current].color = 2;
    }

    return cnt;
}