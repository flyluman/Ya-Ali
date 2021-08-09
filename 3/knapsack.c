#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
    int id;
    float val_p_wt;
} pair;

int max(int x, int y) {
    return x > y ? x : y;
}

int _01_knapsack(int max_weight, int wt[], int val[], int n_items) {

    int (*dp)[max_weight+1] = (int (*)[max_weight+1]) malloc(sizeof(int) * (n_items+1) * (max_weight+1));

    for(int i=0; i<=n_items; i++) {
        for(int j=0; j<=max_weight; j++) {
            if(i == 0 || j == 0) {
                dp[0][0] = 0;
            } else if(wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    free(dp);
    return dp[n_items][max_weight];
}

int cmp(const void *x, const void *y) {
    return ((pair*)x)->val_p_wt < ((pair*)y)->val_p_wt;
}

float fractional_knapsack(int max_weight, int wt[], int val[], int n_items) {
    pair *list = (pair *) malloc(sizeof(pair) * n_items);

    for(int i=0; i<n_items; i++) {
        list[i].id = i;
        list[i].val_p_wt = (float) val[i] / wt[i];
    }

    qsort(list, n_items, sizeof(pair), cmp);

    float ttl_weight = 0, ttl_value = 0;

    for(int i=0; i<n_items; i++) {
        if(ttl_weight + wt[list[i].id] <= max_weight) {
            ttl_weight += wt[list[i].id];
            ttl_value += val[list[i].id];
        } else {
            ttl_value += list[i].val_p_wt * (max_weight - ttl_weight);
            break;
        }
    }

    free(list);
    return ttl_value;
}

int main() {

    int wt[] = {1, 2, 5, 6, 7}, val[] = {1, 6, 18, 22, 28};
    int max_weight = 11, n_items = sizeof(wt) / sizeof(wt[0]);

    printf("Maximum possible value using 01 knapsack is: %d\n", _01_knapsack(max_weight, wt, val, n_items));
    printf("Maximum possible value using fractional knapsack is: %0.2f\n", fractional_knapsack(max_weight, wt, val, n_items));

    return 0;
}
