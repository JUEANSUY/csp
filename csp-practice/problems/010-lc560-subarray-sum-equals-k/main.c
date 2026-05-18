#include <stdio.h>

#define MAXN 100005
#define MOD 200003

int keys[MOD];
int values[MOD];
int used[MOD];

int hash(int key){
    int h = key % MOD;
    if(h<0){
        h += MOD;
    }
    return h;
}

int get(int key){
    int h = hash(key);
    while(used[h]){
        if(keys[h]==key){
            return values[h];
        }
        h++;
        if(h==MOD){
            h = 0;
        }
    }
    return 0;
}

void add(int key){
    int h = hash(key);
    while(used[h]){
        if(keys[h]==key){
            values[h]++;
            return;
        }
        h++;
        if (h==MOD){
            h = 0;
        }
    }
    used[h] = 1;
    keys[h] = key;
    values[h] = 1;
}

int subarraySum(int *nums, int numsSize, int k) {
    for (int i = 0; i < MOD; i++)
    {
        used[i] = 0;
        values[i] = 0;
    }
    int count = 0;
    int sum = 0;
    add(0);
    for (int i = 0; i < numsSize;i++){
        sum += nums[i];
        count += get(sum - k);
        add(sum);
    }
    return count;
}

int main(void) {
    int n;
    int k;
    int nums[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    printf("%d\n", subarraySum(nums, n, k));
    return 0;
}
