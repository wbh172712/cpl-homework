//
// Created by wbh17 on 2023/9/22.
//
#include <stdio.h>
int main(void){
    double M, m, G, R, power;
    G = 6.674e-11;
    M = 77.15;
    scanf("%lf %lf", &m, &R);
    power = G * M * m / (R * R);

    printf("%.3e", power);

    return 0;
}