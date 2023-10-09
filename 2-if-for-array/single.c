//
// Created by wbh17 on 2023/10/8.
//
#include <stdio.h>
int main(void){
    int NUM, single = 0;
    scanf("%d", &NUM);
    int a = 2 * NUM - 1;
    int numbers[a];

    for (int i = 0; i < a; i++) {
        scanf("%d", &numbers[i]);
        single ^= numbers[i];
    }

    printf("%d", single);
    return 0;
}