//
// Created by wbh17 on 2023/11/17.
//
#include <stdio.h>

void rollCube(int a, int b, int c, char change[]) {
    int x1 = 0, y1 = 0, x2 = a, y2 = b;

    for (int i = 0; change[i] != '\0'; ++i) {
        char direction = change[i];

        switch (direction) {
            case 'W':
                x1 -= c;
                x2 -= a;
                int temp1 = a;
                a = c;
                c = temp1;
                break;
            case 'S':
                x1 += a;
                x2 += c;
                int temp2 = a;
                a = c;
                c = temp2;
                break;
            case 'A':
                y1 -= c;
                y2 -= b;
                int temp3 = b;
                b = c;
                c = temp3;
                break;
            case 'D':
                y1 += b;
                y2 += c;
                int temp4 = b;
                b = c;
                c = temp4;
                break;
        }
    }

    printf("%d %d %d %d\n", x1, x2, y1, y2);
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    char change[1005];
    scanf("%s", change);

    rollCube(a, b, c, change);

    return 0;
}
