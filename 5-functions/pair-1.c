//
// Created by wbh17 on 2023/10/28.
//
#include <stdio.h>

int main(void) {
    int n = 0, m = 0, t = 0;
    scanf("%d%d%d", &n, &m, &t);

    int a[10005] = {0};
    int b[10005] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }


    int middle = 0;
    int min = t + 1;
    for(int i = 0; i < m; i++) {
        int high = n - 1;
        int low = 0;
        while(high >= low) {
            middle = (high + low) / 2;
            if (t - b[i] - a[middle] < min && t - b[i] - a[middle] >= 0) {
                min = t - b[i] - a[middle];
            }
            if (t - b[i] - a[middle] > 0) {
                low = middle + 1;
            } else if (t - b[i] - a[middle] < 0) {
                high = middle - 1;
            } else {
                break;
            }
        }

    }

    if (min != t + 1) {
        printf("%d", min);
    } else {
        printf("-1");
    }
    return 0;
}