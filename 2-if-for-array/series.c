//
// Created by wbh17 on 2023/10/8.
//
#include <stdio.h>
int main(void){
    float x;
    int n;
    scanf("%f %d", &x, &n);

    float number1 = x, number2, number3 = x;

    for(int i = 1; i <= n; i++){
        number1 = -1 * number1 * x * x;
        number2 = number1 / (2 * i + 1);
        number3 = number3 + number2;

    }
    printf("%.10f", number3 * 4);

    return 0;
}