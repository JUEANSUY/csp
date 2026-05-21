#include <stdio.h>

#define MAXN 205

void dfs(int **isConnected, int city, int n, int *visited)
{
    visited[city] = 1;
    for (int next = 0; next < n;next++){
        if(isConnected[city][next]==1&&visited[next]==0){
            dfs(isConnected, next, n, visited);
        }
    }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize) {
    (void)isConnectedColSize;

    int count = 0;
    int visited[MAXN] = {0};
    for (int i = 0; i < isConnectedSize; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            dfs(isConnected, i, isConnectedSize, visited);
        }
    }
        return count;
}

int main(void) {
    int n;
    int data[MAXN][MAXN];
    int *isConnected[MAXN];
    int isConnectedColSize[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        isConnected[i] = data[i];
        isConnectedColSize[i] = n;
        for (int j = 0; j < n; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    printf("%d\n", findCircleNum(isConnected, n, isConnectedColSize));
    return 0;
}
