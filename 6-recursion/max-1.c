//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>

int arr[100005];

int main(void) {
    int count;
    scanf("%d", &count);

    for(int i = 1; i <= count; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= count; i++) {
        int l = i;
        int r = i;
        while(arr[l-1] <= arr[i] && l-1 >= 1 && r <= count)l--;
        while(arr[r+1] <= arr[i] && l >= 1 && r+1 <= count)r++;
        printf("%d %d\n", l, r);
    }

    return 0;
}
