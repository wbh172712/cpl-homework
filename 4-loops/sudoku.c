//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>

int main(void) {
    int shudu[9][9] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &shudu[i][j]);
        }
    }

    int result = 1;

    for (int i = 0; i < 9; i++) {
        int b[10] = {0};
        for (int j = 0; j < 9; j++) {
            b[shudu[i][j]]++;
        }
        for (int k = 1; k <= 9; k++) {
            if (b[k] != 1) {
                result = 0;
            }
        }
    }

    for (int j = 0; j < 9; j++) {
        int b[10] = {0};
        for (int i = 0; i < 9; i++) {
            b[shudu[i][j]]++;
        }
        for (int k = 1; k <= 9; k++) {
            if (b[k] != 1) {
                result = 0;
            }
        }
    }

    for (int i = 1; i < 9; i+=3) {
        for (int j = 1; j < 9; j+=3) {
            int plus;
            int multiply;
            plus = shudu[i-1][j-1]+shudu[i-1][j]+shudu[i-1][j+1]+shudu[i][j-1]+shudu[i][j]
                   +shudu[i][j+1]+shudu[i+1][j-1]+shudu[i+1][j]+shudu[i+1][j+1];
            multiply =shudu[i-1][j-1]*shudu[i-1][j]*shudu[i-1][j+1]*shudu[i][j-1]*shudu[i][j]
                      *shudu[i][j+1]*shudu[i+1][j-1]*shudu[i+1][j]*shudu[i+1][j+1];
            if ((plus != 45) || (multiply != 362880)) {
                result = 0;
            }
        }
    }


    if (result == 1) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
