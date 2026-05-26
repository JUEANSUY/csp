#include <stdio.h>
#include <stdlib.h>

#define MAXN 10001

typedef struct
{
    double a;
    double b;
} FlexTask;

int cmpFlex(const void *p1, const void *p2)
{
    FlexTask *x = (FlexTask *)p1;
    FlexTask *y = (FlexTask *)p2;

    double rateX = x->b / x->a;
    double rateY = y->b / y->a;

    if (rateX < rateY)
    {
        return 1;
    }
    if (rateX > rateY)
    {
        return -1;
    }
    return 0;
}

double getFlexReduce(FlexTask flex[], int flexCnt, double left)
{
    double reduce = 0;

    for (int i = 0; i < flexCnt; i++)
    {
        if (left <= 0)
        {
            break;
        }

        if (left >= flex[i].a)
        {
            reduce += flex[i].b;
            left -= flex[i].a;
        }
        else
        {
            reduce += left * (flex[i].b / flex[i].a);
            left = 0;
        }
    }

    return reduce;
}

int main(void)
{
    int n;
    int m;

    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    int o[MAXN], t[MAXN], a[MAXN], b[MAXN];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &o[i], &t[i], &a[i],&b[i]);
        sum += t[i];
    }

    int dp[MAXN];
    for (int i = 0; i < MAXN;i++){
        dp[i] = 0;
    }

    FlexTask flex[MAXN];
    int flexCnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (o[i] == 1)
        {
            for (int j = m; j >= a[i];j--){
                if(dp[j]<dp[j-a[i]]+b[i]){
                    dp[j] = dp[j - a[i]] + b[i];
                }
            }
        }

        if(o[i]==0){
            flex[flexCnt].a = a[i];
            flex[flexCnt].b = b[i];
            flexCnt++;
        }
    }
    qsort(flex, flexCnt, sizeof(FlexTask), cmpFlex);
    double max = 0;
    for (int j = 0; j <= m;j++){
        double car = dp[j] + getFlexReduce(flex, flexCnt, m - j);
        if(max<car){
            max = car;
        }
    }
    printf("%.6f\n", sum - max);
}
