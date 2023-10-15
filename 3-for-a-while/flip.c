//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
int main(void) {
    int NUM;
    scanf("%d", &NUM);
    int sentence[10000] = {0};


    for (int j = 1; j <= NUM; j++){
        for (int i = 1; i <= NUM; i++){
            if (i % j == 0) {
                sentence[i - 1] ++;
            }
        }
    }
    /*
     * for (int i = 0; i < NUM; i++) {
     *    printf("%d", sentence[i]);
     * }
     */
    for (int i = 1; i <= NUM; i++) {
        if (sentence[i - 1] % 2 == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}
