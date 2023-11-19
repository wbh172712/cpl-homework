//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>
#include <math.h>

char result[1005][1005] = {0};

void Paint(int a, int x, int y);

int main(void) {
    int a;
    scanf("%d", &a);

    for(int i = 1; i <= pow(2, a); i++) {
        for (int j = 1; j <= pow(2, a+1); j++) {
            result[i][j] = ' ';
        }
    }

    Paint(a, 2, 1);

    for(int i = 1; i <= pow(2, a); i++) {
        for (int j = 1; j <= pow(2, a+1); j++) {
            printf("%c", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void Paint(int a, int x, int y) {
    if(a == 1) {
        result[x-1][y+1] = '/';
        result[x][y] = '/';
        result[x][y+1] = '_';
        result[x][y+2] = '_';
        result[x][y+3] = '\\';
        result[x-1][y+2] = '\\';
        return;
    }

    Paint(a - 1, x, y + pow(2, a - 1));
    Paint(a - 1, x + pow(2, a - 1), y);
    Paint(a - 1, x + pow(2, a - 1), y + pow(2, a));

}