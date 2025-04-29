#include <stdio.h>

int main() {
    int n, W;
    int p[10], w[10];
    float tot_v = 0.0;
    int cur_w;
    int i, maxi;
    int used[10];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the values and weights of the items:\n");
    for (i = 0; i < n; ++i) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &p[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &w[i]);
    }
    for (i = 0; i < n; ++i) {
        used[i] = 0;
    }
    cur_w = W;
    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i) {
            if (!used[i] && (maxi == -1 || (float)w[i] / p[i] > (float)w[maxi] / p[maxi])) {
                maxi = i;
            }
        }

        used[maxi] = 1;
        cur_w -= p[maxi];
        if (cur_w >= 0) {
            tot_v += w[maxi];
            printf("Added object %d (%d value, %d weight) completely. Space left: %d.\n",
                   maxi + 1, w[maxi], p[maxi], cur_w);
        } else {
            float fraction = 1 + (float)cur_w / p[maxi];
            printf("Added %.2f%% (%d value, %d weight) of object %d.\n",
                   fraction * 100, w[maxi], p[maxi], maxi + 1);
            tot_v += fraction * w[maxi];
            break;
        }
    }
    printf("Total value in knapsack: %.2f\n", tot_v);
    return 0;
}
