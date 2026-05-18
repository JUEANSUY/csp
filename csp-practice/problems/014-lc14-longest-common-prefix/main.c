#include <stdio.h>
#include <string.h>

#define MAXN 205
#define MAXL 205

char *longestCommonPrefix(char **strs, int strsSize) {
    for (int i = 0; strs[0][i]!='\0'; i++)
    {
        for (int j = 1; j < strsSize;j++){
            if(strs[j][i]=='\0'){
                strs[0][i] = '\0';
                return strs[0];
            }
            if(strs[0][i]!=strs[j][i]){
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}

int main(void) {
    int n;
    char strs[MAXN][MAXL];
    char *ptrs[MAXN];

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%204s", strs[i]);
        ptrs[i] = strs[i];
    }

    printf("%s\n", longestCommonPrefix(ptrs, n));
    return 0;
}
