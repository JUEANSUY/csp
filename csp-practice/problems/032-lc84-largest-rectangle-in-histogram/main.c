#include <stdio.h>

#define MAXN 100005

int stack[MAXN];
int TOP = -1;

void push(int x){
    TOP++;
    stack[TOP] = x;
}

void pop(){
    TOP--;
}

int largestRectangleArea(int *heights, int heightsSize) {
    TOP = -1;
    int max = 0;
    for (int i = 0; i <= heightsSize; i++)
    {
        int curHeight = (i == heightsSize) ? 0 : heights[i];

        while (TOP != -1 && curHeight < heights[stack[TOP]])
        {
            int idx = stack[TOP];
            pop();

            int right = i;
            int height = heights[idx];
            int width;

            if (TOP == -1)
            {
                width = right;
            }
            else
            {
                width = right - stack[TOP] - 1;
            }

            int area = height * width;
            if (area > max)
            {
                max = area;
            }
        }

        if (i < heightsSize)
        {
            push(i);
        }
    }
    return max;
}

int main(void) {
    int n;
    int heights[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    printf("%d\n", largestRectangleArea(heights, n));
    return 0;
}
