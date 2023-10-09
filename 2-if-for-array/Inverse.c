//
// Created by wbh17 on 2023/10/8.
//
#include <stdio.h>

int main(void){
    int NUM, k;
    scanf("%d", &NUM);
    getchar();
    char sentence[NUM];
    gets(sentence);

    scanf("%d", &k);
    getchar();
    for (int i = k - 1; i >= 0 ; i--) {
        printf("%c", sentence[i]);
    }
    for (int i = NUM - 1; i >= k; i--) {
        printf("%c", sentence[i]);
    }

    return 0;
}