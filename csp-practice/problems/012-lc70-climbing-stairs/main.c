#include <stdio.h>

int climbStairs(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int a = 1;
    int b = 2;
    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    printf("%d\n", climbStairs(n));
    return 0;
}
