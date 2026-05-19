#include <stdio.h>
#include <stdlib.h>

#define MAXN 30005

int cmpInt(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return x - y;
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmpInt);
    qsort(s, sSize, sizeof(int), cmpInt);

    int x = 0;
    int y = 0;
    int count = 0;

    while (x < gSize && y < sSize)
    {
        if (s[y] >= g[x])
        {
            count++;
            x++;
        }
        y++;
    }

    return count;
}

int main(void) {
    int gSize;
    int sSize;
    int g[MAXN];
    int s[MAXN];

    if (scanf("%d", &gSize) != 1) {
        return 0;
    }

    for (int i = 0; i < gSize; i++) {
        scanf("%d", &g[i]);
    }

    if (scanf("%d", &sSize) != 1) {
        return 0;
    }

    for (int i = 0; i < sSize; i++) {
        scanf("%d", &s[i]);
    }

    printf("%d\n", findContentChildren(g, gSize, s, sSize));
    return 0;
}
