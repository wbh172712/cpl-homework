//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
    int N;
    scanf("%d", &N);
    getchar();
    char sentence[10000];

    for (int i = 0; i < N; i++) {
        gets(sentence);

        int len = strlen(sentence);

        int result = 0;
        int valid = 1;
        for (int j = 0; j < len; j++) {
            if (sentence[j] == '1') {
                result = result + pow(3.0, len - j - 1);
            } else if (sentence[j] == 'Z') {
                result = result - pow(3.0, len - j - 1);
            } else if (sentence[j] != '0') {
                valid = 0;
                break;
            }
        }
        if (valid == 0) {
            printf("Radix Error\n");
        } else {
            printf("%d\n", result);
        }
    }

    return 0;
}
