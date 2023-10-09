//
// Created by wbh17 on 2023/10/9.
//
#include <stdio.h>
int main() {
    int n, k, ch;
    scanf("%d", &n);
    getchar();
    char a[n];
    int i = 0;
    while ((ch = getchar()) != '\n') {
        a[i] = ch;
        i++;
    }

    scanf("%d", &k);
    for (i = k - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }
    for (i = n - 1; i >= k; i--) {
        printf("%c", a[i]);
    }

    return 0;
}
