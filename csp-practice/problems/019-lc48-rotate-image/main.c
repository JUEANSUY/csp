#include <stdio.h>

#define MAXN 105

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
    int temp = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = i + 1; j < matrixSize; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < matrixSize;i++){
        for (int j = 0; j < matrixSize / 2; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1];
            matrix[i][matrixSize - j - 1] = temp;
        }
    }
}

int main(void) {
    int n;
    int data[MAXN][MAXN];
    int *matrix[MAXN];
    int matrixColSize[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = data[i];
        matrixColSize[i] = n;
        for (int j = 0; j < n; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    rotate(matrix, n, matrixColSize);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
