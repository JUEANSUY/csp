#include <stdio.h>

int main(void) {
    int n;
    long long sum = 0;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
        sum += x;
    }

    printf("%lld\n", sum);
    return 0;
}
