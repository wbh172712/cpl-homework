//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int per[2004] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &per[i]);
    }

    int num = 0;
    while (per[n - num - 1] > per[n - num]){
        num++;
    }
    for (int i = n; i >= n - num; i--){
        if (per[n - num - 1] < per[i]) {
            int temp = per[n - num - 1];
            per[n - num - 1] = per[i];
            per[i] = temp;
            break;
        }
    }

    for (int i = n - num, j = n; i < j; i++, j--) {
        int temp = per[i];
        per[i] = per[j];
        per[j] = temp;
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", per[i]);
    }

    return 0;
}
