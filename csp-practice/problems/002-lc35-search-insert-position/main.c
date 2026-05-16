#include <stdio.h>

#define MAXN 100005

int searchInsert(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid; 
    while(left<=right){
        mid = left + (right - left) / 2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}

int main(void) {
    int n;
    int target;
    int nums[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &target);

    printf("%d\n", searchInsert(nums, n, target));
    return 0;
}
