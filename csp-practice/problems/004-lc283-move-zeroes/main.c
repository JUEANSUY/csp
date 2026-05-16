#include <stdio.h>

#define MAXN 100005

void moveZeroes(int *nums, int numsSize) {
    int j = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    for (int i = j; i < numsSize; i++) {
        nums[i] = 0;
    }
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

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", nums[i]);
    }
    printf("\n");

    return 0;
}
