#include <stdio.h>

int climbStairs(int n) {
    /*
     * TODO:
     * 实现 LeetCode 70 Climbing Stairs。
     *
     * 提醒：
     * 1. 每次可以爬 1 阶或 2 阶。
     * 2. 到第 n 阶的最后一步，可能来自 n-1，也可能来自 n-2。
     * 3. 可以先想 dp[n] 和 dp[n-1]、dp[n-2] 的关系。
     */

    return 0;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    printf("%d\n", climbStairs(n));
    return 0;
}
