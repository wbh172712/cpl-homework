//
// Created by wbh17 on 2023/9/22.
//
#include <stdio.h>
int main(void){
    int money, num_fifty, num_twenty, num_ten, num_five, num_one, a, b, c;
    scanf("%d", &money);
    num_fifty = money / 50;
    a = money % 50;
    num_twenty = a / 20;
    b = a % 20;
    num_ten = b / 10;
    c = b % 10;
    num_five = c / 5;
    num_one = c % 5;

    printf("%d\n%d\n%d\n%d\n%d\n", num_fifty, num_twenty, num_ten, num_five, num_one);

    return 0;
}
