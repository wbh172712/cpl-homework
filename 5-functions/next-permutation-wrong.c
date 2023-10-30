//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>
int main(void) {
    int n = 0;
    scanf("%d", &n);

    int per[2004] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &per[i]);
    }

    int num = 0;
    while(per[n - num - 1] > per[n - num]) {
        num++;
    }

    for (int i = 1; i <= num + 1; i++) {
        if (num == 0) {
            int temp = per[n - 1];
            per[n - 1] = per[n];
            per[n] = temp;
        } else if (per[n - num - 1] > per[n - num - 1 + i]) {
            int temp = per[n - num - 1];
            per[n - num - 1] = per[n - num - 2 + i];
            per[n - num - 2 + i] = temp;
            break;
        }
    }

    for (int i = 1; i <= n - num - 1; i++) {
        printf("%d ", per[i]);
    }
    for (int i = n; i >= n - num; i--) {
        printf("%d ", per[i]);
    }

    return 0;
}