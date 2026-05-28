#include <stdio.h>

#define MAXN 10001
#define MAXM 105
#define MAXK 1005

typedef struct
{
    int t;
    int b[MAXK];
    long long xorsum;
} ASK;

int askforcorrect(ASK *s, ASK *t, int i)
{
    int sameSet = 1;

    if (s[i].t != t[i].t)
    {
        sameSet = 0;
    }
    else
    {
        for (int j = 1; j <= s[i].t; j++)
        {
            if (s[i].b[j] != t[i].b[j])
            {
                sameSet = 0;
                break;
            }
        }
    }

    int sameXor = (s[i].xorsum == t[i].xorsum);

    return sameSet == sameXor;
}

int main(void)
{
    int n, m;
    long long a[MAXN];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    ASK s[MAXM];
    ASK t[MAXM];
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &s[i].t);
        s[i].xorsum = 0;
        for (int j = 1; j <= s[i].t; j++)
        {
            scanf("%d", &s[i].b[j]);
            s[i].xorsum ^= a[s[i].b[j]];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &t[i].t);
        t[i].xorsum = 0;
        for (int j = 1; j <= t[i].t; j++)
        {
            scanf("%d", &t[i].b[j]);
            t[i].xorsum ^= a[t[i].b[j]];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int c = askforcorrect(s, t, i);
        if (c == 1)
        {
            printf("correct\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
}
