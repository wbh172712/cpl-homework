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

    int index[1000] = {0};
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (price[index[i]] < price[index[j]]){
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    int result = 0;
    int i = 0;
    while (l > 0) {
        if (l >= amount[index[i]]) {
            l = l - amount[index[i]];
            result = result + amount[index[i]] * price[index[i]];
            i++;
        } else {
            result = result + l * price[index[i]];
            l = 0;
        }
    }

    printf("%d", result);

    return 0;
}