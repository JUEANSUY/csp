#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 10005

char *addStrings(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i = len1 - 1;
    int j = len2 - 1;
    int maxlen = len1 > len2 ? len1 : len2;
    int carry = 0;
    int k = 0;
    int x = 0;
    int y = 0;
    char *result = malloc(maxlen + 2);
    while (i >= 0 || j >= 0 || carry > 0)
    {
        if(i>=0){
            x = num1[i] - '0';
        }
        else{
            x = 0;
        }
        if(j>=0){
            y = num2[j] - '0';
        }
        else{
            y = 0;
        }
        int sum = x + y + carry;
        result[k] = sum % 10 + '0';
        carry = sum / 10;

        i--;
        j--;
        k++;
    }

    result[k] = '\0';
    int l = 0;
    int r = k - 1;
    while (l < r)
    {
        char temp = result[l];
        result[l] = result[r];
        result[r] = temp;
        l++;
        r--;
    }
    return result;
}

int main(void) {
    char num1[MAXL];
    char num2[MAXL];

    if (scanf("%10004s", num1) != 1) {
        return 0;
    }

    if (scanf("%10004s", num2) != 1) {
        return 0;
    }

    printf("%s\n", addStrings(num1, num2));
    return 0;
}
