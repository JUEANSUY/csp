#include <stdio.h>

#define MAXR 15
#define MAXC 15

int queueR[MAXR * MAXC];
int queueC[MAXR * MAXC];
int front;
int rear;

void push(int r, int c)
{
    queueR[rear] = r;
    queueC[rear] = c;
    rear++;
}

void pop(int *r, int *c)
{
    *r = queueR[front];
    *c = queueC[front];
    front++;
}

int empty(void)
{
    return front == rear;
}

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
    int fresh = 0;
    front = 0;
    rear = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i];j++){
            if(grid[i][j]==1){
                fresh++;
            }
            if(grid[i][j]==2){
                push(i, j);
            }
        }
    }
    int minutes = 0;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    while(!empty()&&fresh>0){
        int size = rear - front;
        for (int i = 0; i < size; i++){
            int r, c;
            pop(&r, &c);
            for (int d = 0; d < 4;d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= gridSize || nc < 0 || nc >= gridColSize[nr])
                {
                    continue;
                }
                if(grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    fresh--;
                    push(nr, nc);
                }
            }
        }
        minutes++;
    }
    if(fresh==0){
        return minutes;
    }
    return -1;
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

    printf("%d\n", orangesRotting(grid, rows, gridColSize));
    return 0;
}
