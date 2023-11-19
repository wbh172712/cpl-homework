//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>
int Tile(int a);

int main(void) {
    int a;
    scanf("%d", &a);

    printf("%d", Tile(a));
    return 0;
}

int Tile (int a) {
    if (a <= 3) {
        return a;
    }

    return Tile(a - 1) + Tile(a - 2);
}