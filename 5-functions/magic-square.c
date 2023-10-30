//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>
int main(void) {
    int n = 0;
    scanf("%d", &n);

    int num = 1;
    int square[103][103] = {0};

    int x = 1;
    int y = (n + 1) / 2;
    square[x][y] = num;
    for (int i = 0; i < n * n; i++) {
       if (x == 1 && y != n && square[n][y+1] == 0) {
           x = n;
           y++;
           num++;
           square[x][y] = num;
       } else if (x != 1 && y == n && square[x-1][1] == 0) {
           x--;
           y = 1;
           num++;
           square[x][y] = num;
       } else if (x != 1 && y != n && square[x-1][y+1] == 0) {
           x--;
           y++;
           num++;
           square[x][y] = num;
       } else if (x == 1 && y == n && square[n][1] == 0) {
           x = n;
           y = 1;
           num++;
           square[x][y] = num;
       } else {
           x++;
           num++;
           square[x][y] = num;
       }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }

    return 0;
}