#include <stdbool.h>
#include <stdio.h>

#define MAXN 100005

bool canJump(int *nums, int numsSize) {
    int max=nums[0];
    for (int i = 0; i <=max; i++)
    {
        max = max > nums[i] + i ? max : nums[i] + i;
        if (max >= numsSize-1)
        {
            return true;
        }
    }
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

    printf("%s\n", canJump(nums, n) ? "true" : "false");
    return 0;
}
