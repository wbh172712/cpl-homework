//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
int main(void) {
    int NUM = 0;
    scanf("%d", &NUM);
    char sentence[100000];

    scanf("%s", sentence);

    int num_qq = 0;
    int m, n;
    for (int j = 0; j < (NUM / 2); j++) {
        m = 48 + (num_qq / 10);
        n = 48 + (num_qq % 10);
        if ((sentence[j] == '?') && (sentence[NUM - j - 1] == '?')) {
            printf("%c%c", m, n);
            num_qq++;
        } else if ((sentence[j] == '?') && (sentence[NUM - j - 1] != '?')) {
            printf("%c", sentence[NUM - j - 1]);
        } else if (sentence[j] != '?'){
            printf("%c", sentence[j]);
        }
    }
    for (int j = (NUM / 2); j < NUM; j++) {
        if ((sentence[j] == '?') && (sentence[NUM - j - 1] == '?')) {
            num_qq--;
            m = 48 + (num_qq / 10);
            n = 48 + (num_qq % 10);
            printf("%c%c", n, m);
        } else if ((sentence[j] == '?') && (sentence[NUM - j - 1] != '?')) {
            printf("%c", sentence[NUM - j - 1]);
        } else if (sentence[j] != '?'){
            printf("%c", sentence[j]);
        }
    }
    return 0;
}