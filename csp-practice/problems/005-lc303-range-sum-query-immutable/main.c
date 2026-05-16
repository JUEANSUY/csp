#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int *prefix;
} NumArray;

NumArray* numArrayCreate(int *nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->prefix = malloc(sizeof(int) * (numsSize + 1));
    obj->prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray *obj, int left, int right) {
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(NumArray *obj)
{
    free(obj->prefix);
    free(obj);
}

int main(void) {
    int n;
    int q;
    int nums[MAXN];
    NumArray *arr;

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
        printf("%d\n", numArraySumRange(arr, left, right));
    }

    numArrayFree(arr);
    return 0;
}
