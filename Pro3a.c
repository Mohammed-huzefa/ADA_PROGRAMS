#include <stdio.h>
#define INF 9999
#define MAX 10

void floyd(int p[MAX][MAX], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && p[i][k] + p[k][j] < p[i][j])
                    p[i][j] = p[i][k] + p[k][j];
}

int main() {
    int p[MAX][MAX], n, e, u, v, w;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            p[i][j] = (i == j) ? 0 : INF;

    printf("Enter each edge (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        p[u][v] = w;          /* directed as original; for undirected set p[v][u]=w too */
    }

    printf("\nInput matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    floyd(p, n);

    printf("\nAfter Floyd (shortest path matrix):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    printf("\nThe shortest paths are:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                printf("<%d,%d> = %d\n", i, j, p[i][j]);

    return 0;
}
