#include <stdio.h>

#define V 5
#define E 7

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int cost[V][V]) {
    int mincost = 0, edge_count = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;

    while (edge_count < V - 1) {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        printf("%d - %d : %d\n", a, b, min);
        mincost += min;
        edge_count++;
    }
    printf("Minimum Cost: %d\n", mincost);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    kruskal(graph);
    return 0;
}
