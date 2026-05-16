#include <stdio.h>

#define MAXN 100005

typedef struct {
    int prefix[MAXN];
} NumArray;

NumArray numArrayCreate(int *nums, int numsSize) {
    NumArray obj;

    /*
     * TODO:
     * 预处理前缀和。
     *
     * 提醒：
     * 1. prefix[i] 可以表示前 i 个数的和。
     * 2. 这样 nums[left] 到 nums[right] 的和可以快速算出来。
     * 3. 注意下标要不要整体错开一位。
     */

    return obj;
}

int numArraySumRange(NumArray *obj, int left, int right) {
    /*
     * TODO:
     * 使用前缀和返回 nums[left] + ... + nums[right]。
     */

    return 0;
}

int main(void) {
    int n;
    int q;
    int nums[MAXN];
    NumArray arr;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    arr = numArrayCreate(nums, n);

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int left;
        int right;
        scanf("%d %d", &left, &right);
        printf("%d\n", numArraySumRange(&arr, left, right));
    }

    return 0;
}
