//
// Created by wbh17 on 2023/9/22.
//
#include <stdio.h>
#include <math.h>
int main(void){
    double pi_one, pi_two;
    pi_one = (log(pow(640320, 3) + 744)) / sqrt(163);
    pi_two = 16 * atan(1.0 / 5) - 4 * atan(1.0 / 239);
    printf("%.15f\n%.15f", pi_one, pi_two);

    return 0;
}