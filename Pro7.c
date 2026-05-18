#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value, weight;
    double ratio;
};

int cmp(const void *a, const void *b) {
    return (((struct Item *)b)->ratio > ((struct Item *)a)->ratio) ? 1 : -1;
}

void discreteKnapsack(struct Item items[], int n, int cap) {
    int dp[n + 1][cap + 1];
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= cap; w++)
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (items[i - 1].weight <= w) {
                int take = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
                int leave = dp[i - 1][w];
                dp[i][w] = (take > leave) ? take : leave;
            } else dp[i][w] = dp[i - 1][w];

    printf("Total value obtained for discrete knapsack: %d\n", dp[n][cap]);
}

void continuousKnapsack(struct Item items[], int n, int cap) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        if (cap >= items[i].weight) total += items[i].value, cap -= items[i].weight;
        else { total += cap * items[i].ratio; break; }
    }
    printf("Total value obtained for continuous knapsack: %.2lf\n", total);
}

int main() {
    int n, cap;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &cap);

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(struct Item), cmp);
    discreteKnapsack(items, n, cap);
    continuousKnapsack(items, n, cap);
    return 0;
}
