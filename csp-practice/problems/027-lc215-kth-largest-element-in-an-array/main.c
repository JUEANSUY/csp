#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 100005

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int *nums, int numsSize, int k)
{
    srand((unsigned)time(NULL));

    int target = numsSize - k;
    int left = 0;
    int right = numsSize - 1;
    while(left<=right){
        int pivot = nums[left + rand() % (right - left + 1)];
        int lt = left;
        int i = left;
        int gt = right;

        while (i <= gt)
        {
            if (nums[i] < pivot)
            {
                swap(&nums[lt], &nums[i]);
                lt++;
                i++;
            }
            else if (nums[i] > pivot)
            {
                swap(&nums[i], &nums[gt]);
                gt--;
            }
            else
            {
                i++;
            }
        }

        if(target<lt){
            right = lt - 1;
        }
        else if(target>gt){
            left = gt + 1;
        }
        else{
            return nums[target];
        }
    }
    return -1;
}

int main(void) {
    int n;
    int k;
    int nums[MAXN];

    if (scanf("%d %d", &n, &k) != 2) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", findKthLargest(nums, n, k));
    return 0;
}
