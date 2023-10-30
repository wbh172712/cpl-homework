//
// Created by wbh17 on 2023/10/23.
//

#include <stdio.h>

int main(void) {
    char str[1001] = {0};
    int length = 0;
    scanf("%d", &length);
    scanf("%s", str);
    char a_z[77] = "aA bB cC dD eE fF gG hH iI jJ kK lL mM nN oO pP qQ rR sS tT uU vV wW xX yY zZ";


    int count[100] = {0};
    for (int i = 0; i < 77; i++) {
        for (int j = 0; j < length; j++) {
            if(a_z[i] == str[j] && a_z[i] != ' ') {
                count[i]++;
            }
        }
    }
    int height = 0;
    for (int i = 0; i < 77; i++) {
        if (a_z[i] != ' ' && count[i] > height) {
            height = count[i];
        }
    }
    char result[80][1001] = {0};
    for (int i = 0; i < 77; i++) {
        result[i][0] = a_z[i];
        result[i][1] = '-';
        for (int j = 2; j < height + 2; j++) {
            if (j - 2 < count[i]) {
                result[i][j] = '=';
            }else {
                result[i][j] = ' ';
            }

        }
    }
    int is_first_line;
    for (int i = height + 1; i >= 0; i--) {
        is_first_line = 1;
        for (int j = 0; j < 77; j++) {
            if (count[j] > 0 || (is_first_line == 0 && a_z[j] == ' ' && ( count[j + 1] > 0 || count[j + 2] > 0 ) )) {
                printf("%c", result[j][i]);
                is_first_line = 0;
            }
        }
        printf("\n");
    }
    return 0;
}