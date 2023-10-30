//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>

int main(void) {
    int n, m, key;
    scanf("%d%d%d", &n, &m, &key);

    int a[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int b[1000] = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int valid;
    for(int i = 0; i < m; i++) {
        if (key - a[0] - b[i] > 0) {
            valid = 1;
            break;
        } else {
            valid = 0;
        }
    }
    if (valid == 0) {
        printf("-1");
        return 0;
    }

    int low = 0;
    int high = n - 1;

    int c[1000];
    int d = 0;
    while (low <= high) {
        int mid = (low + high) / 2;

        int bigger = 0;
        for (int i = 0; i < m; i++) {
            if (key - a[mid] - b[i] >= 0) {
                c[d] = key - a[mid] - b[i];
                bigger = 1;
                d++;
            }
        }

        if (bigger) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    int result = c[0];
    for(int i = 1; i < d; i++) {
        if (result > c[i]) {
            result = c[i];
        }
    }

    printf("%d", result);
    return 0;
}
