//
// Created by wbh17 on 2023/11/18.
//
#include <stdio.h>
#include <math.h>
#include <limits.h>

int n, m, len;
int score[605][605] = {0};


int main() {

    scanf("%d%d%d", &n, &m, &len);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &score[i][j]);
        }
    }

    int result[10020][3] = {0};
    int a = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            result[a][1] = i;
            result[a][2] = j;
            for(int p = i - len; p <= i + len; p++) {
                for(int q = abs(i - p) - len + j; q <= len - abs(i - p) + j; q++) {
                    if (p >= 1 && q >= 1 && p <= n && q <= m){
                        result[a][0] += score[p][q];
                    }
                }
            }
            a++;
        }
    }

    int max = INT_MIN;
    for (int i = 0; i < n * m; i++) {
        if (result[i][0] > max) {
            max = result[i][0];
        }
    }

    int count = 0;
    for (int i = 0; i < n * m; i++) {
        if (result[i][0] == max) {
            count++;
        }
    }
    printf("%d %d\n", max, count);

    for (int i = 0; i < n * m; i++) {
        if (result[i][0] == max) {
            printf("%d %d\n", result[i][1], result[i][2]);
        }
    }

    return 0;
}