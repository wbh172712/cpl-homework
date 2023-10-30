//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>
#include <math.h>
int RadixChange(int num, int radix) {
    int change = 0;
    int a = 0;
    int num_1 = num;
    while (num_1 != 0){
        num_1 = num_1 / 10;
        a++;
    }
    int num_2 = num;
    for (int i = 0; i < a; i++) {
        change = change + (num_2 % 10) * pow(radix,i);
        num_2 /= 10;
    }
    return change;
}

int main(void) {
    int p,q,r;
    scanf("%d%d%d", &p, &q, &r);

    int a = 0;
    int num[10] = {0};
    num[p % 10]++;
    num[q % 10]++;
    num[r % 10]++;
    num[p / 10]++;
    num[q / 10]++;
    num[r / 10]++;
    for (int i = 9; i >= 2; i--) {
        if (num[i] != 0) {
            a = i;
            break;
        }
    }

    for (int i = a + 1; i < 100; i++) {
        if (RadixChange(p,i) * RadixChange(q,i) == RadixChange(r,i)) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
    return 0;
}
