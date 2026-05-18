#include <stdio.h>
#define MAX 100

void subsetSum(int set[], int subset[], int n, int index, int subSize, int total, int sum) {
    if (total == sum) {
        printf("Subset found: { ");
        for (int i = 0; i < subSize; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }

    for (int i = index; i < n; i++) {
        subset[subSize] = set[i];
        subsetSum(set, subset, n, i + 1, subSize + 1, total + set[i], sum);
    }
}

int main() {
    int set[MAX], subset[MAX], n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the sum to find subset for: ");
    scanf("%d", &sum);

    printf("Subsets with sum %d:\n", sum);
    subsetSum(set, subset, n, 0, 0, 0, sum);

    return 0;
}
