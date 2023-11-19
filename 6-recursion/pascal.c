//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>
int Pascal(int a, int b);

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d", Pascal(a, b));
    return 0;
}

int Pascal(int a, int b) {
    if (b == 1 || b == a){
        return 1;
    }
    return Pascal(a - 1, b) + Pascal(a - 1, b - 1);
}