//
// Created by wbh17 on 2023/10/25.
//
#include <stdio.h>
#include <math.h>
int main(void){
    double x;
    int n;
    scanf("%lf %d", &x, &n);

    double number = 0;
    for(int i = 0; i <= n; i++){
        number = number + pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
    }
    printf("%.10f", number * 4);

    return 0;
}