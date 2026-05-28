#include <stdio.h>
#include <stdlib.h>

#define MAXP 105
#define MAXQ 8005

typedef struct
{
    long long left;
    long long len;
    long long last;
} Queue;

typedef struct
{
    long long left;
    long long right;
} Segment;

Queue queues[MAXP][MAXQ];
int cnt[MAXP] = {0};
long long nextAddr = 0;
Segment seg[8005];

int cmpSegment(const void *a, const void *b)
{
    Segment *x = (Segment *)a;
    Segment *y = (Segment *)b;

    if (x->left < y->left)
    {
        return -1;
    }
    else if (x->left > y->left)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

long long findAddress(long long L,int n){
    int tot = 0;
    for (int p = 1; p <= n; p++)
    {
        for (int i = 1; i <= cnt[p];i++){
            seg[tot].left = queues[p][i].left;
            seg[tot].right = queues[p][i].left + queues[p][i].len - 1;
            tot++;
        }
    }
    qsort(seg, tot, sizeof(Segment), cmpSegment);

    if(tot==0){
        return 0;
    }

    long long bestleft = -1;
    long long bestlen = -1;

    long long firstFreeLen = seg[0].left;

    if (firstFreeLen >= L)
    {
        bestleft = 0;
        bestlen = firstFreeLen;
    }

    for (int i = 0; i < tot - 1; i++)
    {
        long long freeLeft = seg[i].right + 1;
        long long freeRight = seg[i + 1].left - 1;
        long long freeLen = freeRight - freeLeft + 1;
        if (freeLen >= L)
        {
            if (bestleft == -1 || freeLen < bestlen)
            {
                bestleft = freeLeft;
                bestlen = freeLen;
            }
        }
    }
    if (bestleft != -1)
    {
        return bestleft;
    }
    return seg[tot - 1].right + 1;
}

int main(void)
{
    int n;
    int q;
    if (scanf("%d %d", &n, &q) != 2)
    {
        return 0;
    }
    char cmd[10];

    for (int i = 0; i < q; i++)
    {
        scanf("%s", cmd);

        if (cmd[0] == 'n')
        {
            int p;
            long long L;
            scanf("%d %lld", &p, &L);
            long long addr = findAddress(L, n);
            cnt[p]++;
            queues[p][cnt[p]].left = addr;
            queues[p][cnt[p]].len = L;
            queues[p][cnt[p]].last = -1;
            printf("%lld\n", addr);
        }
        else if (cmd[0] == 's')
        {
            int p;
            scanf("%d", &p);
            long long sum = 0;
            for (int j = 1; j <= cnt[p]; j++)
            {
                if (queues[p][j].last == -1){
                    queues[p][j].last = queues[p][j].left;
                }
                else{
                    queues[p][j].last++;
                    if(queues[p][j].last>=queues[p][j].left+queues[p][j].len){
                        queues[p][j].last = queues[p][j].left;
                    }
                }
                sum += queues[p][j].last;
            }
            printf("%lld\n", sum);
        }
        else if (cmd[0] == 'd')
        {
            int p;
            int id;
            scanf("%d %d", &p, &id);
            for (int j = id; j < cnt[p];j++){
                queues[p][j] = queues[p][j + 1];
            }
            cnt[p]--;
        }
    }
}
