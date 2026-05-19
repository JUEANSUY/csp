#include <stdio.h>

#define MAXN 105

int rob(int *nums, int numsSize) {
    int dp[MAXN];
    if (numsSize == 1)
    {
        return nums[0];
    }
    dp[0] = nums[0];
    dp[1] = nums[0]>nums[1]?nums[0]: nums[1];
    for (int i = 2; i < numsSize;i++){
        dp[i] = dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
    }
    return dp[numsSize-1];
}

int main(void) {
    int n;
    int nums[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", rob(nums, n));
    return 0;
}
