#include <stdio.h>

#define MAXN 100005

int maxProfit(int *prices, int pricesSize) {
    if (pricesSize <= 1)
    {
        return 0;
    }
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        int profit = prices[i] - minPrice;
        if (profit > maxProfit)
        {
            maxProfit = profit;
        }

        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
    }
    return maxProfit;
}

int main(void) {
    int n;
    int prices[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    printf("%d\n", maxProfit(prices, n));
    return 0;
}
