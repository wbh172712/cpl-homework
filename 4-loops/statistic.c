//
// Created by wbh17 on 2023/10/24.
//
#include <stdio.h>

int main(void) {
    char sentence[1001] = {0};
    int num = 0;
    scanf("%d", &num);
    scanf("%s", sentence);
    char pre_result[77] = {0};
    for (int i = 0; i < 77; i+=3) {
        pre_result[0] = 'a';
        pre_result[i] = pre_result[i - 3] + 1;
    }
    for (int i = 1; i < 77; i+=3) {
        pre_result[1] = 'A';
        pre_result[i] = pre_result[i - 3] + 1;
    }
    for (int i = 2; i < 77; i+=3) {
        pre_result[i] = ' ';
    }

    int count[77] = {0};
    for (int i = 0; i < 77; i++) {
        for (int j = 0; j < num; j++) {
            if(pre_result[i] == sentence[j] && pre_result[i] != ' ') {
                count[i]++;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < 77; i++) {
        if (max < count[i]) {
            max = count[i];
        }
    }
    char result[77][1000] = {0};
    for (int i = 0; i < 77; i++) {
        result[i][0] = pre_result[i];
        result[i][1] = '-';
        for (int j = 2; j < max + 2; j++) {
            if (j < count[i] + 2) {
                result[i][j] = '=';
            } else {
                result[i][j] = ' ';
            }

        }
    }

    int judge_first = 1;
    for (int i = max + 1; i >= 0; i--) {
        judge_first = 1;
        for (int j = 0; j < 77; j++) {
            if (count[j] > 0 ||
                    (judge_first == 0 && pre_result[j] == ' ' &&
                    (result[j + 1][2] == '=' || result[j + 2][2] == '=') )) {
                printf("%c", result[j][i]);
                judge_first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}