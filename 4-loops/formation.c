//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>
int main(void) {

    int f[2][2][2] = {
            [0][0][0] = 0,
            [0][0][1] = 1,
            [0][1][0] = 1,
            [0][1][1] = 1,
            [1][0][0] = 0,
            [1][0][1] = 1,
            [1][1][0] = 1,
            [1][1][1] = 0,
    };

    int m, n;
    scanf("%d%d", &m, &n);
    int formation[2001][2001] = {0};
    char front[2001] = {0};

    scanf("%s", front);
    for (int k = 1; k < n + 1; k++) {
        formation[0][k] = front[k - 1] - 48;
    }


    for (int j = 1; j < m; j++) {
        for (int k = 1; k < n + 1; k++) {
            formation[j][k] = f[formation[j - 1][k - 1]][formation[j - 1][k]][formation[j - 1][k + 1]];
        }
    }

    for (int j = 1; j < m; j++) {
        for (int k = 1; k < n + 1; k++) {
            printf("%d", formation[j][k]);
        }
        printf("\n");
    }


    return 0;
}