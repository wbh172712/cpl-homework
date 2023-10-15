//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
int main(void){
    int N, k;
    scanf("%d %d", &N, &k);

    int f_n_k = 0;
    for (int i = 2; i <= N; i++) {
        f_n_k = (f_n_k + k) % i;
    }
    printf("%d", f_n_k + 1);
    return 0;
}