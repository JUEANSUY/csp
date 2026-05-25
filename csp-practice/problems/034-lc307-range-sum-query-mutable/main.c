#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef struct {
    int n;
    int *num;
    int *tree;
} NumArray;

int lowbit(int x)
{
    return x & -x;
}

void add(NumArray *obj, int index, int delta)
{
    while (index <= obj->n)
    {
        obj->tree[index] += delta;
        index += lowbit(index);
    }
}

int prefix(NumArray *obj, int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += obj->tree[i];
        i -= lowbit(i);
    }
    return sum;
}

NumArray* numArrayCreate(int *nums, int numsSize) {
    (void)nums;
    NumArray *obj = malloc(sizeof(NumArray));
    obj->n = numsSize;
    obj->num = malloc(sizeof(int) * numsSize);
    obj->tree = malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i <= numsSize;i++){
        obj->tree[i] = 0;
    }
    for (int i = 0; i < numsSize;i++){
        obj->num[i] = nums[i];
        add(obj, i + 1, nums[i]);
    }
    return obj;
}

void numArrayUpdate(NumArray *obj, int index, int val) {
    int delta = val - obj->num[index];
    add(obj, index + 1, delta);
    obj->num[index] = val;
}

int numArraySumRange(NumArray *obj, int left, int right) {
    return prefix(obj, right + 1) - prefix(obj, left);
}

void numArrayFree(NumArray *obj) {
    free(obj->num);
    free(obj->tree);
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
        char op[16];
        scanf("%15s", op);

        if (strcmp(op, "update") == 0) {
            int index;
            int val;
            scanf("%d %d", &index, &val);
            numArrayUpdate(arr, index, val);
        } else if (strcmp(op, "sum") == 0) {
            int left;
            int right;
            scanf("%d %d", &left, &right);
            printf("%d\n", numArraySumRange(arr, left, right));
        }
    }

    numArrayFree(arr);
    return 0;
}
