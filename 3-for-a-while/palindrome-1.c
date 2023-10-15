//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
int main(void) {
    int NUM = 0;
    scanf("%d", &NUM);
    char sentence[NUM];

    scanf("%s", sentence);
    for (int j = 0; j < NUM; j++){
        if(sentence[j] == '?') {
            printf("%c", sentence[NUM - j - 1]);
        } else {
            printf("%c", sentence[j]);
        }
    }

    return 0;
}