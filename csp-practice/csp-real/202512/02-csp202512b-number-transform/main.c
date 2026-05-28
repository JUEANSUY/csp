#include <stdio.h>

int smallF(int x, int k)
{
    return ((x * x + k * k) % 8) ^ k;
}

int g(int x, int k)
{
    int a = (x >> 6) & 7;
    int b = (x >> 3) & 7;
    int c = x & 7;

    int na = b;
    int nb = c ^ smallF(b, k);
    int nc = a ^ smallF(c, k);

    return (na << 6) + (nb << 3) + nc;
}

int main(void) {
    int n, m;
    int k[1005];
    int a[500005];

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &k[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans[512];

    for (int origin = 0; origin < 512; origin++)
    {
        int x = origin;

        for (int j = 1; j <= m; j++)
        {
            x = g(x, k[j]);
        }

        ans[x] = origin;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d", ans[a[i]]);

        if (i < n)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
}

