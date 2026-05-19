#include <stdio.h>
#include <string.h>

#define MAXL 10005

int strStr(char *haystack, char *needle) {
    for (int i = 0; haystack[i] != '\0';i++){
        if(needle[0]==haystack[i]){
            int ok = 1;
            for (int j = 0; needle[j] != '\0'; j++)
            {
                if(needle[j]!=haystack[i+j]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                return i;
            }
        }
    }
        return -1;
}

int main(void) {
    char haystack[MAXL];
    char needle[MAXL];

    if (scanf("%10004s", haystack) != 1) {
        return 0;
    }

    if (scanf("%10004s", needle) != 1) {
        return 0;
    }

    printf("%d\n", strStr(haystack, needle));
    return 0;
}
