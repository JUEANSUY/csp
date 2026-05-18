#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005

int cmpInterval(const void *a, const void *b)
{
    const int *x = (const int *)a;
    const int *y = (const int *)b;

    return x[0] - y[0];
}

int merge(int intervals[MAXN][2], int intervalsSize, int result[MAXN][2]) {
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmpInterval);
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    int count = 1;
    for (int i = 1; i < intervalsSize; i++)
    {
        if(result[count-1][1]>=intervals[i][0]){
            if(result[count-1][1]<intervals[i][1]){
                result[count-1][1] = intervals[i][1];
            }
        }
        else{
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
            count++;
        }
    }
        return count;
}

int main(void) {
    int n;
    int intervals[MAXN][2];
    int result[MAXN][2];
    int returnSize;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    returnSize = merge(intervals, n, result);

    for (int i = 0; i < returnSize; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}
