//
// Created by wbh17 on 2023/9/22.
//
#include <stdio.h>
#include <math.h>
int main(void){
   int year, month, day, a, y, m, JDN;
   scanf("%d %d %d", &year, &month, &day);

   a = (14 - month) / 12;
   y = year + 4800 - a;
   m = month + 12 * a - 3;
   JDN = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

    printf("%d", JDN);
    return 0;
}