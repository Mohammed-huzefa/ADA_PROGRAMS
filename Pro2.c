#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int visited[], int V) {
    int min = INT_MAX, index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void prim(int graph[MAX][MAX], int V) {
    int parent[MAX], key[MAX], visited[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Edge      Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d      %d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int V, E, graph[MAX][MAX] = {0};

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter the source vertex, destination vertex, and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        graph[s][d] = w;
        graph[d][s] = w;
    }

    prim(graph, V);
    return 0;
}
