#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 205

bool canPartition(int *nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize;i++){
        sum += nums[i];
    }
    if(sum % 2==1){
        return false;
    }
    int target = sum / 2;
    bool *dp = malloc(sizeof(bool) * (target + 1));
    for (int i = 0; i < target + 1;i++){
        dp[i] = false;
    }
    dp[0] = true;
    for (int i = 0; i <numsSize; i++){
        int num = nums[i];
        for (int j = target; j >= num;j--){
            dp[j] = dp[j] || dp[j - num];
        }
    }
    bool ans = dp[target];
    free(dp);
    return ans;
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

    printf("%s\n", canPartition(nums, n) ? "true" : "false");
    return 0;
}
