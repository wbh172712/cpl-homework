
//
// Created by Sunny on 2023/10/18.
//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int k = 0; k < n; ++k) {
        int decimal;
        int ternary[5000] = {0};
        int i = 0;
        scanf("%d", &decimal);
        char illegal = getchar();
        if (illegal == '\n') {
            if (decimal == 0) {
                printf("0\n");
            } else if (decimal > 0) {
                while (decimal > 0) {
                    ternary[i] = decimal % 3;
                    decimal = decimal / 3;
                    i++;
                }

                char b_ternary[5000];

                for (int j = 0; j < i; ++j) {
                    if (ternary[j] == 0) {
                        b_ternary[j] = '0';
                    } else if (ternary[j] == 1) {
                        b_ternary[j] = '1';
                    } else if (ternary[j] == 2) {
                        b_ternary[j] = 'Z';
                        ternary[j + 1] = ternary[j + 1] + 1;
                    } else {
                        b_ternary[j] = '0';
                        ternary[j + 1] = ternary[j + 1] + 1;
                    }
                }

                if (ternary[i] == 1) {
                    printf("1");
                }

                for (int j = i - 1; j >= 0; --j) {
                    printf("%c", b_ternary[j]);
                }
                printf("\n");
            } else {
                decimal = -decimal;
                while (decimal > 0) {
                    ternary[i] = decimal % 3;
                    decimal = decimal / 3;
                    i++;
                }

                char b_ternary[5000];

                for (int j = 0; j < i; ++j) {
                    if (ternary[j] == 0) {
                        b_ternary[j] = '0';
                    } else if (ternary[j] == 1) {
                        b_ternary[j] = 'Z';
                    } else if (ternary[j] == 2) {
                        b_ternary[j] = '1';
                        ternary[j + 1] = ternary[j + 1] + 1;
                    } else {
                        b_ternary[j] = '0';
                        ternary[j + 1] = ternary[j + 1] + 1;
                    }
                }

                if (ternary[i] == 1) {
                    printf("Z");
                }

                for (int j = i - 1; j >= 0; --j) {
                    printf("%c", b_ternary[j]);
                }
                printf("\n");
            }
        } else {
            do {
                illegal = getchar();
            } while (illegal != '\n');
            printf("Radix Error\n");
        }
    }

    return 0;
}