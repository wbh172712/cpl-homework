
//
// Created by Sunny on 2023/10/9.
//
#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; ++i) {
        int legal = 1;
        int ten = 0;
        char next_char[1000], ch;
        int a[1000];
        int j = 0;

        while ((ch = getchar()) != '\n') {
            next_char[j] = ch;
            j = j + 1;
        }

        for (int i = 0; i < j; ++i) {
            if (next_char[i] == '1') {
                a[i] = 1;
            } else if (next_char[i] == '0') {
                a[i] = 0;
            } else if (next_char[i] == 'Z') {
                a[i] = -1;
            } else {
                legal = 0;
                break;
            }
        }

        for (int i = 0; i < j; ++i) {
            ten = ten + a[i] * pow(3, j - i - 1);
        }

        if (legal == 1) {
            printf("%d\n", ten);
        } else {
            printf("Radix Error\n");
        }
    }

    return 0;
}

