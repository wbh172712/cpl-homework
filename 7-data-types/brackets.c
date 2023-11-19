//
// Created by wbh17 on 2023/11/17.
//
#include <stdio.h>
#include <string.h>

int main (void) {
    int n = 0;
    scanf("%d", &n);

    char bracket[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", bracket);

        int l = 0;
        int r = 0;
        int len = strlen(bracket);
        int result = 1;

        while (l + r < len) {
            int j = l + r;
            int m = l + r;
            while (bracket[j] == '(' || bracket[j] == '[' || bracket[j] == '{') {
                l++;
                j++;
                if (bracket[j] != '(' && bracket[j] != '[' && bracket[j] != '{') {
                    break;
                }
            }

            while (bracket[j] == ')' || bracket[j] == ']' || bracket[j] == '}') {
                r++;
                j++;
                if (bracket[j] != ')' && bracket[j] != ']' && bracket[j] != '}') {
                    break;
                }
            }

            if(l != r) {
                result = 0;
                goto print;
            }

            for (int k = m, i = 0; k < (l + r + m) / 2; k++, i++) {
                if (bracket[k] == '(' && bracket[l + r - i - 1] != ')') {
                    result = 0;
                    goto print;
                } else if (bracket[k] == '[' && bracket[l + r - i - 1] != ']'){
                    result = 0;
                    goto print;
                } else if (bracket[k] == '{' && bracket[l + r - i - 1] != '}'){
                    result = 0;
                    goto print;
                }
            }
        }
        print:
        if (result) {
            printf("True\n");
        } else {
            printf("False\n");
        }

    }

    return 0;
}