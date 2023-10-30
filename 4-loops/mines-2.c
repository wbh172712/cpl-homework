//
// Created by wbh17 on 2023/10/25.
//
#include <stdio.h>

char mines[105][105];
int vectors[8][2] = {{-1, -1},
                     {-1, 0},
                     {-1, 1},
                     {1, -1},
                     {1, 0},
                     {1, 1},
                     {0, 1},
                     {0, -1} };

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", mines[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mines[i][j] == 'o') {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    // 注意 newI 和 newJ 必须是合法的坐标值
                    if (newI >= 0 && newI < n && newJ >= 0 &&
                        newJ < n && mines[newI][newJ] == '*')
                        count++;
                }
                printf("%d", count);
            } else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}
