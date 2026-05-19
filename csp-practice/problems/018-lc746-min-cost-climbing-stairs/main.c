#include <stdio.h>

#define MAXN 1005

int minCostClimbingStairs(int *cost, int costSize) {
    int dp[MAXN];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= costSize; i++)
    {
        int a = dp[i - 1] + cost[i - 1];
        int b = dp[i - 2] + cost[i - 2];
        dp[i] = a < b ? a : b;
    }

    return dp[costSize];
}

int main(void) {
    int n;
    int cost[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    printf("%d\n", minCostClimbingStairs(cost, n));
    return 0;
}
