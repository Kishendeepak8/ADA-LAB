#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsackBruteForce(int W, int weights[], int values[], int n) {
    int max_value = 0;
    for (int i = 0; i < (1 << n); i++) {
        int total_weight = 0;
        int total_value = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total_weight += weights[j];
                total_value += values[j];
            }
        }
        if (total_weight <= W) {
            max_value = max(max_value, total_value);
        }
    }

    return max_value;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int weights[n], values[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }
    int max_value = knapsackBruteForce(W, weights, values, n);
    printf("Maximum value in the knapsack is: %d\n", max_value);

    return 0;
}
