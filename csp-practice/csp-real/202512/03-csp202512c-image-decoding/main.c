#include <stdio.h>

int z;
int rot = 0;

void mapPos(int x, int y, int *rx, int *ry)
{
    if (rot == 0)
    {
        *rx = x;
        *ry = y;
    }
    else if (rot == 1)
    {
        *rx = z - 1 - y;
        *ry = x;
    }
    else if (rot == 2)
    {
        *rx = z - 1 - x;
        *ry = z - 1 - y;
    }
    else
    {
        *rx = y;
        *ry = z - 1 - x;
    }
}

char getCell(char a[z][z], int x, int y)
{
    int rx, ry;
    mapPos(x, y, &rx, &ry);
    return a[rx][ry];
}

void setCell(char a[z][z], int x, int y, char val)
{
    int rx, ry;
    mapPos(x, y, &rx, &ry);
    a[rx][ry] = val;
}

void swapCell(char a[z][z], int x1, int y1, int x2, int y2)
{
    char t = getCell(a, x1, y1);
    setCell(a, x1, y1, getCell(a, x2, y2));
    setCell(a, x2, y2, t);
}

void rotate(char a[z][z], int *k, int m)
{
    rot = (rot + k[m + 4]) % 4;

    int d = k[m + 3] / 90;
    int u = k[m] - 1;
    int v = k[m + 1] - 1;
    int L = k[m + 2];

    for (int r = 0; r < d; r++)
    {
        for (int i = u; i < u + L; i++)
        {
            for (int l = v, r = v + L - 1; l < r; l++, r--)
            {
                swapCell(a, i, l, i, r);
            }
        }
        for (int i = 0; i < L; i++)
        {
            for (int j = i + 1; j < L; j++)
            {
                swapCell(a, u + i, v + j, u + j, v + i);
            }
        }
    }
}

void flip(char a[z][z], int *k, int m)
{
    int u = k[m] - 1;
    int d = k[m + 1] - 1;
    int l = k[m + 2] - 1;
    int r = k[m + 3] - 1;
    int o = k[m + 4];

    if (o == -1)
    {
        for (int row = u; row <= d; row++)
        {
            for (int left = l, right = r; left < right; left++, right--)
            {
                swapCell(a, row, left, row, right);
            }
        }
    }

    if (o == 1)
    {
        for (int up = u, down = d; up < down; up++, down--)
        {
            for (int col = l; col <= r; col++)
            {
                swapCell(a, up, col, down, col);
            }
        }
    }
}

int main(void)
{
    scanf("%d", &z);

    char a[z][z];
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < z; j++)
        {
            scanf(" %c", &a[i][j]);
        }
    }

    int n;
    scanf("%d", &n);
    int k[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }

    for (int j = n - 6; j >= 1; j -= 6)
    {
        if (k[j] == 1)
        {
            rotate(a, k, j + 1);
        }
        else
        {
            flip(a, k, j + 1);
        }
    }

    int row = z;
    int col = z;

    for (int i = 0; i < z; i++)
    {
        if (getCell(a, i, 0) == '?')
        {
            row = i;
            break;
        }
    }

    for (int j = 0; j < z; j++)
    {
        if (getCell(a, 0, j) == '?')
        {
            col = j;
            break;
        }
    }

    printf("%d %d\n", row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c", getCell(a, i, j));
        }
        printf("\n");
    }
}
