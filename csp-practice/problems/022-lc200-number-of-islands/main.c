#include <stdio.h>

#define MAXR 305
#define MAXC 305
int rows;
int cols;
char data[MAXR][MAXC];
char *grid[MAXR];
int gridColSize[MAXR];
void dfs(char**grid,int row,int col){
    if(row<0||row>=rows||col<0||col>=cols){
        return;
    }
    if(grid[row][col]!='1'){
        return;
    }
    grid[row][col] = '0';
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
}
int numIslands(char **grid, int gridSize, int *gridColSize) {
    rows = gridSize;
    cols = gridColSize[0];
    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i];j++){
            if(grid[i][j]=='1'){
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main(void) {


    if (scanf("%d %d", &rows, &cols) != 2) {
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        scanf("%304s", data[i]);
        grid[i] = data[i];
        gridColSize[i] = cols;
    }

    printf("%d\n", numIslands(grid, rows, gridColSize));
    return 0;
}
