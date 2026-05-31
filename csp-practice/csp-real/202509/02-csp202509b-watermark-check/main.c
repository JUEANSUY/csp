#include <stdio.h>

int csp[5][9] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 0}};
int n;
int L;
int ok[65536] = {0};
void check(int x, int y, int a[n][n])
{
    int low = 0;
    int high = L - 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int val = a[x + i][y + j];
            if (csp[i][j] == 1)
            {
                if (val < high)
                {
                    high = val;
                }
            }
            else
            {
                if (val + 1 > low)
                {
                    low = val + 1;
                }
            }
        }
    }
    if (low <= high)
    {
        for (int k = low; k <= high; k++)
        {
            ok[k] = 1;
        }
    }
}
int main(void)
{
    scanf("%d %d", &n, &L);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int x = 0; x + 4 < n; x++)
    {
        for (int y = 0; y + 8 < n; y++)
        {
            check(x, y, a);
        }
    }
    for (int i = 0; i < L; i++)
    {
        if (ok[i] == 1)
        {
            printf("%d\n", i);
        }
    }
}
