#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N (100000 + 50)

int T, top;
bool vis[N];
char s[N], stk[N];

int main() {
    scanf("%d", &T);
    for (int n; T--; ) {
        scanf("%s", s);
        n = strlen(s), top = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') stk[++top] = ch;
            else {
                if (!top) {
                    ok = false;
                    break;
                }
                if ((ch == ')' && stk[top] != '(') || (ch == ']' && stk[top] != '[') || (ch == '}' && stk[top] != '{')) {
                    ok = false;
                    break;
                }
                --top;
            }
        }
        ok &= (top == 0);
        puts(ok ? "True" : "False");
    }
    return 0;
}