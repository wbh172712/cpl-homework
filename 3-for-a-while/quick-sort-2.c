//
// Created by wbh17 on 2023/10/15.
//
#include <stdio.h>

void exchange( int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(void) {

    int n = 0;
    int k = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int pivot = arr[k - 1];
    int l = 0;
    int r = n - 1;
    while(r > l) {

        while (arr[l] < pivot ) {
            l++;
        }
        while (arr[r] >= pivot ) {
            r--;
        }
        if(r > l) {
            exchange( &arr[l], &arr[r]);
            if(l == k - 1) {
                k = r + 1;
            }
        }
    }
    exchange( &arr[l], &arr[k - 1]);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
