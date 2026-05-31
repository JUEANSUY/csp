#include <stdio.h>
#include <math.h>
int main(void) {
    int n, a;
    scanf("%d %d", &n, &a);
    double x,y;
    double cnt = 0;
    for (int i = 0; i < n;i++){
        scanf("%lf %lf", &x, &y);
        if (x * x + y * y <= (double)a * a)
        {
            cnt++;
        }
    }
    double p;
    p = 4 * cnt / n;
    printf("%lf", p);
}
