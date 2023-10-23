//
// Created by wbh17 on 2023/10/15.
//
#include <stdio.h>

int main(void) {
    int n, k;
    int p = 0;
    int a[900] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n + 1; i++){
        a[i] = 1;
    }
    while (p < k * (n - 1)) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                p++;
            }
            if (p % k == 0) {
                a[i] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if(a[i] == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}