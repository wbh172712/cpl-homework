//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool IsPrime(int x) {
    for (int i = 2; i <= sqrt(x + 0.5); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n = 0;
    scanf("%d", &n);

    int count = 0;
    for(int num = 2; num <= n; num++) {
        int num_1 = num;
        int a = 0;
        while (num_1 != 0) {
            num_1 = num_1 / 10;
            a++;
        }

        int num_2 = num;
        int back = 0;
        for (int i = 0; i < a; i++) {
            back = back + (num_2 % 10) * pow(10,a - i - 1);
            num_2 = num_2 / 10;
        }

        if (IsPrime(num) && IsPrime(back)) {
            count++;
        }
    }

    printf("%d", count);
    return 0;
}
