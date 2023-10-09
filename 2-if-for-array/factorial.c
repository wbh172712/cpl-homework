//
// Created by wbh17 on 2023/10/8.
//
#include <stdio.h>
int main(void){
    int number;
    scanf("%d", &number);

    int num1 = 1, result = 0;
    for (int i = 1; i <= number; i++) {
        num1 = (num1 * i) % 10007;
        result = (result + num1) % 10007;
    }

    printf("%d", result);
    return 0;
}