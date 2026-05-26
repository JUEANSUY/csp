#include <stdio.h>

#define MAXN 105

int isBalanced(int x) {
    int count0 = 0;
    int count1 = 0;
    while (x > 0)
    {
        int bit = x % 2;
        if(bit==0){
            count0++;
        }
        if(bit==1){
            count1++;
        }
        x /= 2;
    }
    if(count0==count1){
        return 1;
    }
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

