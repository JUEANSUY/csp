#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005

int coinChange(int *coins, int coinsSize, int amount) {
    int dp[MAXN];
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = amount + 1;
    }
    dp[0] = 0;
    for (int i = 0; i < coinsSize; i++)
    {
        int num = coins[i];
        for (int j = num; j <= amount; j++)
        {
            if (dp[j - num] + 1 < dp[j])
            {
                dp[j] = dp[j - num] + 1;
            }
        }
    }
    if (dp[amount] == amount + 1)
    {
        return -1;
    }
    return dp[amount];
}

int main(void) {
    int n;
    int amount;
    int coins[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    scanf("%d", &amount);

    printf("%d\n", coinChange(coins, n, amount));
    return 0;
}
