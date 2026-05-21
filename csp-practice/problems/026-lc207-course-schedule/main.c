#include <stdbool.h>
#include <stdio.h>

#define MAXN 2005
#define MAXE 5005

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize) {
    (void)prerequisitesColSize;

    static int graph[MAXN][MAXN];
    int graphSize[MAXN] = {0};
    int indegree[MAXN] = {0};
    for (int i = 0; i < prerequisitesSize;i++){
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphSize[b]] = a;
        graphSize[b]++;
        indegree[a]++;
    }
    int queue[MAXN];
    int front = 0;
    int rear = 0;
    for (int i = 0; i < numCourses;i++){
        if(indegree[i]==0){
            queue[rear] = i;
            rear++;
        }
    }
    int learned = 0;
    while(front<rear){
        int course = queue[front];
        front++;
        learned++;
        for (int i = 0; i < graphSize[course];i++){
            int next = graph[course][i];
            indegree[next]--;
            if (indegree[next] == 0){
                queue[rear] = next;
                rear++;
            }
        }
    }
    return learned == numCourses;
}

int main(void) {
    int numCourses;
    int prerequisitesSize;
    int data[MAXE][2];
    int *prerequisites[MAXE];
    int prerequisitesColSize[MAXE];

    if (scanf("%d %d", &numCourses, &prerequisitesSize) != 2) {
        return 0;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        prerequisites[i] = data[i];
        prerequisitesColSize[i] = 2;
        scanf("%d %d", &data[i][0], &data[i][1]);
    }

    printf("%s\n", canFinish(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize) ? "true" : "false");
    return 0;
}
