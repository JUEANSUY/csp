#include <stdio.h>

#define MAXN 100005

int largestRectangleArea(int *heights, int heightsSize) {
    (void)heights;
    (void)heightsSize;
    return 0;
}

int main(void) {
    int n;
    int heights[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    printf("%d\n", largestRectangleArea(heights, n));
    return 0;
}
