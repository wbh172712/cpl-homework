//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>

int main(void) {
    char board[50][50] = {0};

    int n, m, x0, y0;
    scanf("%d%d%d%d", &n, &m, &x0, &y0);

    for (int i = 0; i < n; i++){
        char row[50];
        scanf("%s", row);
        for (int j = 0; j < m; j++) {
            board[i][j] = row[j];
        }
    }

    char new_board[52][52] = {0};
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++) {
            new_board[i][j] = board[i - 1][j - 1];
        }
    }

    int count = 0;
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++) {
            if (new_board[i][j] == '#') {
                count++;
            }
        }
    }
    printf("%d\n", count);
    printf("%d %d\n", x0, y0);

    while((new_board[x0 - 1][y0] == '#') ||
            (new_board[x0 + 1][y0] == '#') ||
            (new_board[x0][y0 - 1] == '#') ||
            (new_board[x0][y0 + 1] == '#')) {
        if (new_board[x0 - 1][y0] == '#') {
            new_board[x0][y0] = 0;
            x0 = x0 - 1;
            printf("%d %d\n", x0, y0);
        } else if (new_board[x0 + 1][y0] == '#') {
            new_board[x0][y0] = 0;
            x0 = x0 + 1;
            printf("%d %d\n", x0, y0);
        } else if (new_board[x0][y0 - 1] == '#') {
            new_board[x0][y0] = 0;
            y0 = y0 - 1;
            printf("%d %d\n", x0, y0);
        } else if (new_board[x0][y0 + 1] == '#') {
            new_board[x0][y0] = 0;
            y0 = y0 + 1;
            printf("%d %d\n", x0, y0);
        }
    }

    return 0;
}
