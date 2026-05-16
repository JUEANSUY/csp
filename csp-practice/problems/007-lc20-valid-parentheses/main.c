#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXN 10005

bool isValid(char *s) {
    char stack[MAXN];
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) {    
                return false;
            }
            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') 
                || (c == '}' && topChar != '{') 
                || (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return top == -1;
}

int main(void) {
    char s[MAXN];

    if (scanf("%10004s", s) != 1) {
        return 0;
    }

    printf("%s\n", isValid(s) ? "true" : "false");
    return 0;
}
