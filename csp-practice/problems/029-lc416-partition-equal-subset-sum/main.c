#include <stdbool.h>
#include <stdio.h>

#define MAXN 205

bool canPartition(int *nums, int numsSize) {
    (void)nums;
    (void)numsSize;

    /*
     * TODO:
     * 在这里写 LeetCode 416 的函数逻辑。
     *
     * 提醒：
     * - 如果数组总和是奇数，不可能分成两个和相等的子集。
     * - 如果总和是 sum，目标就是找一个子集和为 sum / 2。
     * - 这题可以转成 0/1 背包 DP。
     */
    return false;
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
