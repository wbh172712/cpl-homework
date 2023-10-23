//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>
#include <string.h>
int main(void) {
    int n;
    scanf("%d", &n);

    char place[1000] = {0};
    scanf("%s", place);
    int len = strlen(place);

    char new_place[1006] = {0};
    char result_place[1006] = {0};
    for (int i = 3; i < len + 3; i++) {
        new_place[i] = place[i - 3];
        result_place[i] = new_place[i];
    }

    for (int j = 0; j < n; j++) {
        for (int i = 3; i < len + 3; i++) {
            if (new_place[i] == 'A') {
                for (int k = -3; k <= 3; k++) {
                    if (new_place[i + k] == 'B') {
                        result_place[i] = '.';
                    }
                }

                int count_A = 0;
                for (int k = -3; k <= 3; k++) {
                    if (new_place[i + k] == 'A') {
                        count_A++;
                    }
                }
                if ((count_A >= 6) || (count_A <= 2)) {
                    result_place[i] = '.';
                }

            } else if (new_place[i] == 'B') {
                for (int k = -3; k <= 3; k++) {
                    if (new_place[i + k] == 'A') {
                        result_place[i] = '.';
                    }
                }

                int count_B = 0;
                for (int k = -3; k <= 3; k++) {
                    if (new_place[i + k] == 'B') {
                        count_B++;
                    }
                }
                if ((count_B >= 6) || (count_B <= 2)) {
                    result_place[i] = '.';
                }
            } else if (new_place[i] == '.') {
                int count_A = 0;
                int count_B = 0;
                for (int k = -3; k <= 3; k++) {
                    if (new_place[i + k] == 'A') {
                        count_A++;
                    }
                    if (new_place[i + k] == 'B') {
                        count_B++;
                    }
                }
                if ((count_A >= 2) && (count_A <= 4) && (count_B == 0)) {
                    result_place[i] = 'A';
                } else if ((count_B >= 2) && (count_B <= 4) && (count_A == 0)) {
                    result_place[i] = 'B';
                }
            }
        }
        for (int i = 3; i < len + 3; i++) {
            new_place[i] = result_place[i];
        }
    }

    for (int i = 3; i < len + 3; i++) {
        printf("%c", result_place[i]);
    }

    return 0;
}
