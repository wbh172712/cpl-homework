//
// Created by wbh17 on 2023/9/22.
//
#include <stdio.h>
#include <math.h>
int main(void){
    int p, q;
    scanf("%d %d", &p, &q);
    double num, a, b, c , d;
    a = p * 1.0/ 3;
    b = q * 1.0/ 2;
    c = cbrt(- b + sqrt(b * b + a * a * a));
    d = cbrt(- b - sqrt(b * b + a * a * a));
    num = c + d;
    printf("%.3f", num);

    return 0;
}