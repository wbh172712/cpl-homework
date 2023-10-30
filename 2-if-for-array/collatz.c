//
// Created by wbh17 on 2023/10/8.
//
#include <stdio.h>
int main(void){
    int number;
    scanf("%d", &number);
    int time = 0, max = number;

    while (number != 1) {
        if (number % 2 == 0) {
            number = number / 2;
            time++;
        } else {
            number = number * 3 + 1;
            time++;
        }
        if (max <= number) {
            max = number;
        }
    }

    printf("%d %d", time, max);
    return 0;
}