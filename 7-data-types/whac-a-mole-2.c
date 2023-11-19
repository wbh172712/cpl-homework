#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BASE 50
int n, m, d;
int a[710][710];
int v[710][710];

int main() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = BASE + 1; i <= BASE + n; i++) {
        for (int j = BASE + 1; j <= BASE + m; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] += a[i][j - 1];
        }
        for (int j = BASE + m + 1; j <= 2 * BASE + m; j++)
            a[i][j] = a[i][j - 1];
    }
    for (int i = BASE + 1; i <= BASE + n; i++) {
        for (int j = BASE + 1; j <= BASE + m; j++) {
            for (int k = -d; k <= d; k++) {
                v[i][j] += a[i + k][j + d - abs(k)] - a[i + k][j - d + abs(k) - 1];
            }
        }
    }
    int max = INT32_MIN, cnt = 0;
    for (int i = BASE + 1; i <= BASE + n; i++) {
        for (int j = BASE + 1; j <= BASE + m; j++) {
            if (max < v[i][j]) {
                max = v[i][j];
                cnt = 1;
            } else if (max == v[i][j])
                cnt++;
        }
    }
    printf("%d %d\n", max, cnt);
    for (int i = BASE + 1; i <= BASE + n; i++) {
        for (int j = BASE + 1; j <= BASE + m; j++) {
            if (max == v[i][j])
                printf("%d %d\n", i - BASE, j - BASE);
        }
    }
}
