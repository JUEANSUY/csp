#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005

int cmpInterval(const void *a, const void *b) {
    /*
     * TODO:
     * qsort 比较函数。
     * 提醒：先按区间起点排序。
     */

    return 0;
}

int merge(int intervals[MAXN][2], int intervalsSize, int result[MAXN][2]) {
    /*
     * TODO:
     * 实现 LeetCode 56 Merge Intervals 的核心逻辑。
     *
     * 提醒：
     * 1. 先按区间左端点排序。
     * 2. 维护当前已经合并好的最后一个区间。
     * 3. 如果新区间和最后一个区间重叠，就更新右端点。
     * 4. 如果不重叠，就把新区间加入结果。
     *
     * 返回合并后的区间个数。
     */

    return 0;
}

int main(void) {
    int n;
    int intervals[MAXN][2];
    int result[MAXN][2];
    int returnSize;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    returnSize = merge(intervals, n, result);

    for (int i = 0; i < returnSize; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}
