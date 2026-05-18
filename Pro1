#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src, dest, wt;
} Edge;

typedef struct {
    int parent;
} Subset;

int find(Subset s[], int i) {
    while (s[i].parent != i)
        i = s[i].parent;
    return i;
}

void unionSet(Subset s[], int x, int y) {
    s[x].parent = y;
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->wt - ((Edge *)b)->wt;
}

int main() {
    int V, E, i, count = 0;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[E], mst[V - 1];
    Subset s[V];

    printf("Enter edges and their weights:\n");
    for (i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].wt);

    for (i = 0; i < V; i++)
        s[i].parent = i;

    qsort(edges, E, sizeof(Edge), compare);

    for (i = 0; i < E && count < V - 1; i++) {
        int x = find(s, edges[i].src);
        int y = find(s, edges[i].dest);

        if (x != y) {
            mst[count++] = edges[i];
            unionSet(s, x, y);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < count; i++)
        printf("(%d, %d) -> %d\n", mst[i].src, mst[i].dest, mst[i].wt);

    return 0;
}
