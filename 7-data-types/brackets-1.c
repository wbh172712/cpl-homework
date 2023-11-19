//
// Created by wbh17 on 2023/11/17.
//
#include <stdio.h>
#include <string.h>

char s[100005];
char stack [100005], *tp = stack;

void init() {
    tp = stack;
}

void push(char c) {
    *(tp++) = c;
}

void pop() {
    tp--;
}

char top() {
    return *(tp - 1);
}

int empty() {
    return tp == stack;
}

int main() {
    int T, len, flag;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        len = strlen(s);
        init();
        flag = 1;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                push(s[i]);
            else {
                if (empty() || s[i] - top() > 2 || s[i] < top()) {
                    flag = 0;
                    break;
                }
                pop();
            }
        }

        puts(flag == 0 ? "False" : "True");
    }
    return 0;

}