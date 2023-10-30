//
// Created by wbh17 on 2023/10/27.
//
#include <stdio.h>
int main(void) {
    int p,q,r;
    scanf("%d%d%d", &p, &q, &r);

    int a = 0;
    int num[6] = {p % 10,q % 10,r % 10};
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
        int changed_p = (p / 10) % 10 * i + p % 10;
        int changed_q = (q / 10) % 10 * i + q % 10;
        int changed_r = (r / 10) % 10 * i + r % 10;

        if (changed_p * changed_q == changed_r) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
    return 0;
}
