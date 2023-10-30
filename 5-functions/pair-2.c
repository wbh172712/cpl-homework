//
// Created by wbh17 on 2023/10/28.
//
#include <stdio.h>

int BinarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);

    int a[10005] = {0};
    int b[10005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }


    int min_sum = -1;

    for (int j = 0; j < m; j++) {
        int target = t - b[j];
        if (target >= a[0]) {
            int index = BinarySearch(a, n, target);
            if (index != -1) {
                int current_sum = t - a[index] - b[j];
                if (min_sum == -1 || current_sum < min_sum) {
                    min_sum = current_sum;
                }
            }
        }
    }

    printf("%d\n", min_sum);

    return 0;
}
