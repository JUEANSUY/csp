#include <stdio.h>

#define MAXR 55
#define MAXC 55

int dfs(int **grid, int row, int col, int rows, int cols){
    if(row<0||row>=rows||col<0||col>=cols){
        return 0;
    }
    if(grid[row][col]!=1){
        return 0;
    }
    grid[row][col] = 0;
    return 1
        + dfs(grid, row - 1, col, rows, cols)
        + dfs(grid, row + 1, col, rows, cols)
        + dfs(grid, row, col - 1, rows, cols)
        + dfs(grid, row, col + 1, rows, cols);
}
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int max = 0;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i];j++){
            if(grid[i][j]==1){
                int area = dfs(grid, i, j, rows, cols);
                max = max > area ? max : area;
            }
        }
    }
    return max;
}

int main(void) {
    int rows;
    int cols;
    int data[MAXR][MAXC];
    int *grid[MAXR];
    int gridColSize[MAXR];

    if (scanf("%d %d", &rows, &cols) != 2) {
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        grid[i] = data[i];
        gridColSize[i] = cols;
        for (int j = 0; j < cols; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    printf("%d\n", maxAreaOfIsland(grid, rows, gridColSize));
    return 0;
}
