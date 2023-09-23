//
// Created by wbh17 on 2023/9/22.
//

#include <stdio.h>
int main(void){
    int day, year, hour, minute, second;
    char month[10], weekday[10];

    scanf("%s %d %d %s %d %d %d", &month, &day, &year, &weekday, &hour, &minute, &second);

    printf("%.3s %.3s %02d %02d:%02d:%02d %04d", weekday, month, day, hour, minute, second, year);
    return 0;
}