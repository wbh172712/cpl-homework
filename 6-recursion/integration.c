//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>
#include <math.h>

double abs_f(double a);

double mid(double c, double d);

double f(double x);

double simpson(double c, double d);

double self_simpson(double c, double d, double e);

int n, p;
int arr[25] = {0};
double a, b;


int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%lf%lf", &a, &b);

    printf("%.6f\n", self_simpson(a, b, 0.0001));

    return 0;
}

double abs_f(double t) {
    return t >= 0 ? t : -t;
}

double mid(double c, double d) {
    return (c + d) / 2.0;
}

double f(double x) {
    double y = 0;
    for (int i = 0; i <= n; ++i) {
        y += arr[i] * pow(x, i);
    }
    return pow(y, p);
}

double simpson(double c, double d) {
    double s;
    s = (4 * f(mid(c, d)) + f(c) + f(d)) * (d - c) / 6.0;
    return s;
}

double self_simpson(double c, double d, double e) {
    double s = simpson(c, d);
    double sl = simpson(c, mid(c, d));
    double sr = simpson(mid(c, d), d);
    if (abs_f(sl + sr - s) <= 15 * e) {
        return (sl + sr + (sl + sr - s) / 15.0);
    } else {
        return self_simpson(c, mid(c, d), e/2.0) + self_simpson(mid(c, d), d, e/2.0);
    }
}