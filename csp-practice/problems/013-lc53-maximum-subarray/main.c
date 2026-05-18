#include <stdio.h>

#define MAXN 100005

int maxSubArray(int *nums, int numsSize) {
    int current = nums[0];
    int answer = nums[0];

    for (int i = 1;i<numsSize;i++){
        if(current + nums[i] > nums[i]){
            current = current + nums[i];
        } 
        else{
            current = nums[i];
        }
        if (current > answer ){
            answer = current;
        }
    }
    return answer;
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

    printf("%d\n", maxSubArray(nums, n));
    return 0;
}
