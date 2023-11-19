//
// Created by wbh17 on 2023/11/18.
//
#include <stdio.h>

int K, va, vb, vc, a0, b0, c0, ans;

void Add(int* c1, int* c2, int v1, int v2) {
    int sum = *c1 + *c2;
    if (sum > v2) {
        sum = v2;
    }
    *c1 = 0;
    *c2 = sum;
}

void Solve(int time, int a, int b, int c) {

    if (time < 0){
        return;
    }
    if (a == a0 && b == b0 && c == c0) {
        ans = 1;
        return;
    }

    int a1 = a;
    int b1 = b;
    int c1 = c;

    a = a1, b = b1, c = c1;
    Add(&a, &b, va, vb);
    Solve(time - 1, a, b, c);

    a = a1, b = b1, c = c1;
    Add(&b, &a, vb, va);
    Solve(time - 1, a, b, c);

    a = a1, b = b1, c = c1;
    Add(&a, &c, va, vc);
    Solve(time - 1, a, b, c);

    a = a1, b = b1, c = c1;
    Add(&c, &a, vc, va);
    Solve(time - 1, a, b, c);

    a = a1, b = b1, c = c1;
    Add(&b, &c, vb, vc);
    Solve(time - 1, a, b, c);

    a = a1, b = b1, c = c1;
    Add(&c, &b, vc, vb);
    Solve(time - 1, a, b, c);
}

int main() {
    int a, b, c;
    scanf("%d%d%d%d%d%d%d%d%d%d", &K, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);

    Solve(K, a, b, c);

    if (ans == 1) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}