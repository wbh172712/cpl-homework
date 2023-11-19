//
// Created by wbh17 on 2023/11/17.
//
#include <stdio.h>
#include <stdbool.h>

#define maxn 10006
char stack[maxn],op[10];
int p = 0, n;

bool empty(void) {
    return p == 0;
}

void push(void) {
    scanf("%c", &stack[p]);
    p++;
}

void pop(void) {
    if (empty()) {
        printf("Empty\n");
    } else {
        p--;
    }
}

void top(void) {
    if (empty()) {
        printf("Empty\n");
    } else {
        printf("%c\n", stack[p - 1]);
    }
}

void print(void) {
    if (empty()) {
        printf("Empty\n");
        return;
    }
    for (int i = p - 1; i >= 0; i--)
        printf("/ %c /\n", stack[i]);
    printf("/===/\n");
}

int main(int argc,char *argv[]) {
    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);
        if (op[2] == 's') {
            push();
        } else if (op[0] == 'p' && op[1] == 'o') {
            pop();
        } else if (op[0] == 't') {
            top();
        } else if (op[1] == 'r') {
            print();
        }
    }

    return 0;
}