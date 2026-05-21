#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize) {
    int stack[MAXN] = {0};
    int TOP = -1;
    *returnSize = temperaturesSize;
    int *answer = malloc(sizeof(int) * temperaturesSize);
    for (int i = 0; i < temperaturesSize;i++){
        answer[i] = 0;
    }
        for (int i = 0; i < temperaturesSize; i++)
        {
            while (TOP >= 0&&temperatures [i] > temperatures[stack[TOP]])
            {
                int idx = stack[TOP];
                TOP--;
                answer[idx] = i - idx;
            }
            TOP++;
            stack[TOP] = i;
        }
    return answer;
}

int main(void) {
    int n;
    int temperatures[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &temperatures[i]);
    }

    int returnSize = 0;
    int *answer = dailyTemperatures(temperatures, n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", answer[i]);
    }
    printf("\n");

    free(answer);
    return 0;
}
