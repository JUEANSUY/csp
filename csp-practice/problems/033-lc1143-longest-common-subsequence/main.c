#include <stdio.h>
#include <string.h>

#define MAXN 1005

int longestCommonSubsequence(char *text1, char *text2) {
    static int dp[MAXN][MAXN];
    int length1 = strlen(text1);
    int length2 = strlen(text2);
    for (int i = 1; i <= length1;i++){
        for (int j = 1; j <= length2;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    return dp[length1][length2];
}

int main(void) {
    char text1[MAXN];
    char text2[MAXN];

    if (scanf("%1004s", text1) != 1) {
        return 0;
    }

    if (scanf("%1004s", text2) != 1) {
        return 0;
    }

    printf("%d\n", longestCommonSubsequence(text1, text2));
    return 0;
}
