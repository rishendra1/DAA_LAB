#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;
    if (smallest != idx) {
        struct MinHeapNode* smallestNode = heap->array[smallest];
        struct MinHeapNode* idxNode = heap->array[idx];
        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

void build_heap(struct MinHeap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--)
        minHeapify(heap, i);
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

struct MinHeapNode* extract_min(struct MinHeap* heap) {
    if (isEmpty(heap)) return NULL;
    struct MinHeapNode* root = heap->array[0];
    struct MinHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;
    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;
    --heap->size;
    minHeapify(heap, 0);
    return root;
}

void decrease_key(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;
    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(struct MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

void printArr(int dist[], int n) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t%d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    struct MinHeap* heap = createMinHeap(V);
    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        heap->array[v] = newMinHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }
    dist[src] = 0;
    heap->array[src] = newMinHeapNode(src, dist[src]);
    heap->pos[src] = src;
    decrease_key(heap, src, dist[src]);
    heap->size = V;
    build_heap(heap);
    while (!isEmpty(heap)) {
        struct MinHeapNode* heapNode = extract_min(heap);
        int u = heapNode->v;
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && isInMinHeap(heap, v) && dist[u] != INT_MAX && graph[u][v] + dist[u] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decrease_key(heap, v, dist[v]);
            }
        }
    }
    printArr(dist, V);
}

int main() {
    int graph[V][V] = {
        {0, 9, 6, 0, 0},
        {9, 0, 0, 5, 0},
        {6, 0, 0, 2, 8},
        {0, 5, 2, 0, 7},
        {0, 0, 8, 7, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
