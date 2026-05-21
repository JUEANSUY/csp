#include <stdio.h>

#define MAXN 2505

int lengthOfLIS(int *nums, int numsSize) {
    int dp[MAXN];

    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize;j++){
            if(nums[j]>nums[i]){
                if(dp[j]<dp[i]+1){
                    dp[j] = dp[i] + 1;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if(dp[i]>max){
            max = dp[i];
        }
    }
    return max;
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

    printf("%d\n", lengthOfLIS(nums, n));
    return 0;
}
