#include <stdio.h>

#define MAXN 105

int isBalanced(int x) {
    (void)x;
    return 0;
}

int main(void) {
    int n;
    int ans = 0;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (isBalanced(a)) {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}

