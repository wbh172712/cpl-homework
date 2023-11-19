//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>
int f[10005];
int Find(int i);
int result[10005];
int main(void) {
    int a;
    scanf("%d", &a);
    for(int i = 1; i <= a; i++) {
        scanf("%d", &f[i]);
    }

    for(int i = 1; i <= a; i++) {
        result[i] = Find(i);
    }

    for(int i = 1; i <= a; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}

int Find(int i) {
    if(f[i] == i) {
        return i;
    } else {
        return Find(f[i]);
    }
}