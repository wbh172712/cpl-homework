//
// Created by wbh17 on 2023/11/18.
//
#include<stdio.h>

int result[10000][2] = {0};

void Move(int arr[][2], int index, int len) {
    for (int i = len - 1; i > index && i >= 0; i--) {
        arr[i][0] = arr[i - 1][0];
        arr[i][1] = arr[i - 1][1];
    }
}

int main(void) {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);

    result[0][0] = 0;
    result[0][1] = n;
    int parts = 1;
    char operation = 0;
    for (int j = 0; j < q; j++) {
        getchar();
        scanf("%c", &operation);

        if(operation == 'Q') {
            printf("%d\n", parts);
            for (int i = parts - 1; i >= 0 ; i--) {
                printf("%d ", result[i][0]);
            }
            printf("\n");
        }

        if (operation == 'A') {
            int finish = 0;
            int id = 0;
            int num = 0;
            scanf("%d%d", &id, &num);

            int space = 0;
            if (num % 2 == 0 || num == 1) {
                num--;
            }
            while(num > 0) {
                num /= 2;
                space++;
            }

            while(finish != 1) {
                for (int i = parts - 1; i >= 0; i--) {
                    if (result[i][0] == 0 && result[i][1] == space) {
                        result[i][0] = id;
                        finish = 1;
                        break;
                    }
                }
                if (finish == 0) {
                    for (int i = parts - 1; i >= 0; i--) {
                        if (result[i][0] == 0 && result[i][1] > space){
                            parts++;
                            result[i][1]--;
                            Move(result, i, parts);
                            result[i][0] = 0;
                            result[i][1] = result[i + 1][1];
                            break;
                        }
                    }
                }
            }
        }
    }


    return 0;
}