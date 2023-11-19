//
// Created by wbh17 on 2023/11/18.
//
#include <stdio.h>
#include <math.h>

int main (void) {

    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);

    int place[1000] = {0};
    place[0] = pow(2, n);

    int result[1000] = {0};
    int parts = 1;

    for (int i = 0; i < q; i++) {
        getchar();
        char operation;
        scanf("%c", &operation);

        if (operation == 'Q') {
            printf("%d\n", parts);
            for (int j = parts - 1; j >= 0; j--) {
                printf("%d ", result[j]);
            }
            printf("\n");
        }

        if (operation == 'A') {
            int id, num;
            scanf("%d%d", &id, &num);

            for (int k = 0; k < 30; k++) {
                if (num > pow(2, k) && num < pow(2, k + 1)){
                    num = pow(2, k + 1);
                    break;
                }
            }

            int again;
            do {
                again = 0;
                int is_break = 1;
                int chucun = 0;
                for (int j = parts - 1; j >= 0; j--) {
                    if (place[j] == num) {
                        place[j] = 0;
                        result[j] = id;
                        is_break = 0;
                        chucun = 1;
                        break;
                    }
                }
                if (is_break) {
                    place[parts - 1 - chucun] = place[parts - 1 - chucun] / 2;
                    place[parts] = place[parts - 1];
                    parts++;
                    again = 1;
                }
            } while (again);

        }

    }

    return 0;
}