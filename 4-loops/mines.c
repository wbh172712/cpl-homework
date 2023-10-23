//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>

int main(void) {
    char board[100][100] = {0};
    char old_board[102][102] = {0};
    char new_board[102][102] = {0};

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%s", board[i]);
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++) {
            if (board[i - 1][j - 1] == '*') {
                old_board[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++) {
            if (board[i - 1][j - 1] == 'o') {
                new_board[i][j] =
                        old_board[i - 1][j - 1] +
                        old_board[i - 1][j] +
                        old_board[i - 1][j + 1] +
                        old_board[i][j - 1] +
                        old_board[i][j + 1] +
                        old_board[i + 1][j - 1] +
                        old_board[i + 1][j] +
                        old_board[i + 1][j + 1] + 48;
            } else {
                new_board[i][j] = board[i - 1][j - 1];
            }
        }
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++) {
            printf("%c", new_board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
