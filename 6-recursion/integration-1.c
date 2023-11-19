//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>
#include <math.h>

double f(int nums[], int n, int p, double x) {
    double result = 0.0;
    for (int i = 0; i <= n; i++) {
        result += nums[i] * pow(x, i);
    }
    return pow(result, p);
}

double Add(int nums[], int n, int p, double l , double r) {
    return (4.0 * f(nums, n, p,(l + r) / 2.0) + f(nums, n, p, l) + f(nums, n, p, r)) / 6.0 * (r - l);
}


double Integration(int nums[], int n, int p, double l , double r, double wucha) {
    double mid = (l + r) / 2.0;
    double SL = Add(nums, n, p, l, mid);
    double SR = Add(nums, n, p,mid, r);
    double S = Add(nums, n, p, l, r);
    if (fabs(SL + SR - S) <= 15.0 * wucha) {
        return SL + SR + (SL + SR - S) / 15.0;
    }
    return Integration(nums, n, p, l, mid, wucha / 2.0) + Integration(nums, n, p, mid, r, wucha / 2.0);
}

int main() {
    int n, p;
    scanf("%d%d", &n, &p);

    int nums[25] = {0};
    for (int i = 0; i <= n; i++)
        scanf("%d", &nums[i]);

    double a, b;
    scanf("%lf%lf", &a, &b);

    printf("%.6f\n", Integration(nums, n, p, a, b, 1e-5));
    return 0;
}