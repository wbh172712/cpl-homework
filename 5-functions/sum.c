//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>
int main(void) {
    int n, t;
    scanf("%d%d", &n, &t);

    int sum = 0;
    int higher_t = 0;
    for(int i = 0; i < n; i++) {
        higher_t = 10 * higher_t + t;
        sum = sum + higher_t;
    }

    printf("%d", sum);
    return 0;
}