//
// Created by wbh17 on 2023/11/17.
//
#include <stdio.h>

int main (void) {
    int n = 0;
    int l = 0;
    scanf("%d%d", &n, &l);

    int price[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    int amount[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &amount[i]);
    }

    int result = 0;
    while (l > 0) {
        int max = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (max < price[i]) {
                max = price[i];
                index = i;
            }
        }
        if (l >= amount[index]) {
            l = l - amount[index];
            result = result + amount[index] * price[index];
            price[index] = 0;
        } else {
            result = result + l * price[index];
            l = 0;
            price[index] = 0;
        }
    }


    printf("%d", result);

    return 0;
}