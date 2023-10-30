//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    char sentence[1000];
    scanf("%s", sentence);

    int num[52] = {0};
    for (int i = 0; i < n; i++) {
        char ch = sentence[i];
        if (ch >= 'a' && ch <= 'z') {
            num[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            num[ch - 'A' + 26]++;
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        char ch = sentence[i];
        if (ch >= 'a' && ch <= 'z') {
            if (max < num[ch - 'a']) {
                max = num[ch - 'a'];
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            if (max < num[ch - 'A' + 26]) {
                max = num[ch - 'A' + 26];
            }
        }
    }

    char pre_result[100][100] = {0};
    for (int i = 0; i < 77; i+=3) {
        pre_result[0][0] = 'a';
        pre_result[i][0] = pre_result[i - 3][0] + 1;
        for (int j = 2; j < num[i/3] + 2; j++) {
            pre_result[i][j] = '=';
        }
        for (int j = num[i/3] + 2; j < max + 2; j++) {
            pre_result[i][j] = ' ';
        }
    }
    for (int i = 1; i < 77; i+=3) {
        pre_result[1][0] = 'A';
        pre_result[i][0] = pre_result[i - 3][0] + 1;
        for (int j = 2; j < num[i/3 + 26] + 2; j++) {
            pre_result[i][j] = '=';
        }
        for (int j = num[i/3 + 26] + 2; j < max + 2; j++) {
            pre_result[i][j] = ' ';
        }
    }

    for (int i = 2; i < 77; i+=3) {
        pre_result[i][0] = ' ';
        for (int j = num[i/3 + 26] + 2; j < max + 2; j++) {
            pre_result[i][j] = ' ';
        }
    }
    for (int i = 0; i < 77; i++) {
        pre_result[i][1] = '-';
    }

    char result[100][100] = {0};
    int a = 0;
    int q;
    for (int i = 0; i < 77; i++) {
        q = 1;
        if (pre_result[i][2] == '=' || (pre_result[i][0] == ' ' &&
                                         q == 0 && (pre_result[i + 1][2] == '=' || pre_result[i + 2][2] == '='))) {
            q = 0;
            for (int j = 0; j < max + 2; j++) {
                result[a][j] = pre_result[i][j];
            }
            a++;
        }
    }

    for (int i = max + 1; i >= 0; i--) {
        for (int j = 0; j < a; j++) {
            printf("%c", result[j][i]);
        }
        printf("\n");
    }

    return 0;
}
