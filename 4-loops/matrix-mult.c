//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>
int main(void) {
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);

    int matrix_1[100][100];
    int matrix_2[100][100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix_1[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &matrix_2[i][j]);
        }
    }

    int matrix_3[m][p];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum = sum + matrix_1[i][k] * matrix_2[k][j];
            }
            matrix_3[i][j] = sum;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", matrix_3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
