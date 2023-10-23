//
// Created by wbh17 on 2023/10/21.
//
#include <stdio.h>
#include <math.h>
int main(void) {

    int xa, ya, xb, yb, xc, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);

    if ((xa != xb) && (ya != yb)) {
        printf("%d\n", abs(xa - xb) + abs(ya - yb));
        if ((xc != xa) && (yc != yb)) {
            for (int i = 0; i < abs(ya - yb); i++) {
                printf("%c", ((ya - yb > 0) ? 'D' : 'U'));
            }
            for (int i = 0; i < abs(xa - xb); i++) {
                printf("%c", ((xa - xb > 0) ? 'L' : 'R'));
            }
        } else {
            for (int i = 0; i < abs(xa - xb); i++) {
                printf("%c", ((xa - xb > 0) ? 'L' : 'R'));
            }
            for (int i = 0; i < abs(ya - yb); i++) {
                printf("%c", ((ya - yb > 0) ? 'D' : 'U'));
            }
        }
    } else if ((xa == xb) && (ya != yb)) {
        if ((xc == xa) &&
            (yc >= ((ya - yb > 0) ? yb : ya)) &&
            (yc <= ((ya - yb > 0) ? ya : yb))) {
            printf("%d\n", abs(ya - yb) + 2);
            printf("R");
            for (int i = 0; i < abs(ya - yb); i++) {
                printf("%c", ((ya - yb > 0) ? 'D' : 'U'));
            }
            printf("L");
        } else {
            printf("%d\n", abs(ya - yb));
            for (int i = 0; i < abs(ya - yb); i++) {
                printf("%c", ((ya - yb > 0) ? 'D' : 'U'));
            }
        }
    } else if ((xa != xb) && (ya == yb)) {
        if ((yc == ya) &&
            (xc >= ((xa - xb > 0) ? xb : xa)) &&
            (xc <= ((xa - xb > 0) ? xa : xb))) {
            printf("%d\n", abs(xa - xb) + 2);
            printf("U");
            for (int i = 0; i < abs(xa - xb); i++) {
                printf("%c", ((xa - xb > 0) ? 'L' : 'R'));
            }
            printf("D");
        } else {
            printf("%d\n", abs(xa - xb));
            for (int i = 0; i < abs(xa - xb); i++) {
                printf("%c", ((xa - xb > 0) ? 'L' : 'R'));
            }
        }
    }

    return 0;
}