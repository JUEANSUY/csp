#include <stdio.h>
#include <stdlib.h>

#define MAXN 105

int* spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {
    int n = matrixColSize[0];
    int *result = (int *)malloc(sizeof(int) * matrixSize * n);
    int index = 0;
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = n - 1;
    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;
        for (int j = top; j <= bottom; j++) {
            result[index++] = matrix[j][right];
        }
        right--;
        if (top<=bottom){
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }
        if (left<=right) {
            for (int j = bottom; j >= top; j--) {
                result[index++] = matrix[j][left];
            }
            left++;
        }
    }
    *returnSize = matrixSize * n;
    return result;
}

int main(void) {
    int m;
    int n;
    int raw[MAXN][MAXN];
    int *matrix[MAXN];
    int matrixColSize[MAXN];
    int returnSize;
    int *ans;

    if (scanf("%d %d", &m, &n) != 2) {
        return 0;
    }

    for (int i = 0; i < m; i++) {
        matrix[i] = raw[i];
        matrixColSize[i] = n;
        for (int j = 0; j < n; j++) {
            scanf("%d", &raw[i][j]);
        }
    }

    ans = spiralOrder(matrix, m, matrixColSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");

    free(ans);
    return 0;
}
