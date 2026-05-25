#include <stdbool.h>
#include <stdio.h>

#define MAXN 200005
#define MAXM 200005

bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source, int destination) {
    (void)n;
    (void)edges;
    (void)edgesSize;
    (void)edgesColSize;
    (void)source;
    (void)destination;
    return false;
}

int main(void) {
    int n;
    int m;
    int source;
    int destination;
    static int edgeData[MAXM][2];
    static int *edges[MAXM];
    static int edgesColSize[MAXM];

    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edgeData[i][0], &edgeData[i][1]);
        edges[i] = edgeData[i];
        edgesColSize[i] = 2;
    }

    scanf("%d %d", &source, &destination);

    printf("%s\n", validPath(n, edges, m, edgesColSize, source, destination) ? "true" : "false");
    return 0;
}
