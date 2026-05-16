#include <stdio.h>

#define MAXN 100005

int removeElement(int *nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main(void) {
    int n;
    int val;
    int nums[MAXN];
    int len;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &val);

    len = removeElement(nums, n, val);
    printf("%d\n", len);

    for (int i = 0; i < len; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", nums[i]);
    }
    printf("\n");

    return 0;
}
