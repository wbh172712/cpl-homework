//
// Created by wbh17 on 2023/10/8.
//
#include <stdio.h>

int main(void) {
    int max;
    scanf("%d", &max);
    int number[max];

    for (int i = 0; i <= max; i++) {
        scanf("%d", &number[i]);
    }

    int tuo = 0, pretuo, a = 0;
    for(int i = 1; i <= max; i++){
        a = a + number[i-1];
        pretuo = i - a;
        if (tuo <= pretuo) {
            tuo = pretuo;
        }
    }
    printf("%d", tuo);
    return 0;
}