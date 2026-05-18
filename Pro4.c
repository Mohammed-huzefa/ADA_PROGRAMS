#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10
#define INF INT_MAX

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, idx = -1;
    for (int i = 0; i < V; i++)
        if (!sptSet[i] && dist[i] <= min)
            min = dist[i], idx = i;
    return idx;
}

void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX];
    bool sptSet[MAX] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V, E, graph[MAX][MAX] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the source vertex, destination vertex, and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        graph[s][d] = w;
        graph[d][s] = w;
    }

    dijkstra(graph, 0, V);
    return 0;
}
