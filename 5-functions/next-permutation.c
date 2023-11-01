//
// Created by wbh17 on 2023/10/27.
//

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[2005] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int p = n;
    while (a[p - 1] > a[p]) {
        p--;
    }

    for (int i = n; i >= p; i--) {
        if (a[p - 1] < a[i]) {
            int tmp = a[p - 1];
            a[p - 1] = a[i];
            a[i] = tmp;
            break;
        }
    }

    for (int i = p, j = n; i < j; i++, j--) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}