#include <stdio.h>

void warshall(int p[10][10], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}

int main() {
    int p[10][10] = {0}, n, e, u, v;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    for (int i = 1; i <= e; i++) {
        printf("\nEnter the end vertices of edge %d: ", i);
        scanf("%d%d", &u, &v);
        p[u][v] = 1;
    }

    printf("\nMatrix of input data:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    warshall(p, n);

    printf("\nTransitive closure:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    return 0;
}
