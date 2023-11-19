#include <stdio.h>
#include <limits.h>

#define MAX_N 605
#define MAX_M 605
#define MAX_POINTS 100005

int map[MAX_N][MAX_M];
int px[MAX_POINTS], py[MAX_POINTS], cnt;

int main() {
    const int offset = 100;
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_M; j++) {
            map[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = i + offset;
            int y = j + offset;
            scanf("%d", &map[x][y]);
        }
    }

    int sum = 0, max = INT_MIN;

    for (int i = 1; i <= n; i++) {
        int x = i + offset;
        sum = 0;

        for (int j = 0; j <= d; j++) {
            for (int k = j - d; k <= d - j; k++) {
                sum += map[x + k][j + 1 + offset];
            }
        }

        if (sum >= max) {
            if (sum > max) {
                cnt = 0;
                max = sum;
            }
            px[cnt] = i;
            py[cnt++] = 1;
        }

        for (int j = 2; j <= m; j++) {
            for (int k = 0; k <= d; k++) {
                sum -= map[x + d - k][j + offset - k - 1];
                sum += map[x + d - k][j + offset + k];

                if (d != k) {
                    sum -= map[x - d + k][j + offset - k - 1];
                    sum += map[x - d + k][j + offset + k];
                }
            }

            if (sum >= max) {
                if (sum > max) {
                    cnt = 0;
                    max = sum;
                }
                px[cnt] = i;
                py[cnt++] = j;
            }
        }
    }

    printf("%d %d\n", max, cnt);

    for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", px[i], py[i]);
    }

    return 0;
}
