//
// Created by wbh17 on 2023/11/17.
//
#include <stdio.h>
#include <string.h>

int is_valid_brackets(char bracket[]) {
    int len = strlen(bracket);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (bracket[i] == '(' || bracket[i] == '[' || bracket[i] == '{') {
            stack[++top] = bracket[i];
        } else if (top >= 0 &&
                   ((bracket[i] == ')' && stack[top] == '(') ||
                    (bracket[i] == ']' && stack[top] == '[') ||
                    (bracket[i] == '}' && stack[top] == '{'))) {
            top--;
        } else {
            return 0; // Mismatched or unmatched closing bracket
        }
    }

    return top == -1; // If the stack is empty, brackets are valid
}

int main(void) {
    int n = 0;
    scanf("%d", &n);

    char bracket[1000];
    for (int i = 0; i < n; i++) {
        scanf("%s", bracket);
        int result = is_valid_brackets(bracket);

        if (result) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }

    return 0;
}
