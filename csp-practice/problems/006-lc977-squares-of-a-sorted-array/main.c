#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int* sortedSquares(int *nums, int numsSize, int *returnSize) {
    int *result = malloc(sizeof(int) * numsSize);
    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1;
    while (left <= right)
    {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        if(leftSquare > rightSquare){
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }
        index--;
    }
    *returnSize = numsSize;
    return result;
}

int main(void) {
    int n;
    int nums[MAXN];
    int returnSize;
    int *ans;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    ans = sortedSquares(nums, n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");

    free(ans);
    return 0;
}
