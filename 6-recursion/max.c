//
// Created by wbh17 on 2023/11/12.
//
#include <stdio.h>

int arr[10005];
int result[10005][2];
int Max(int arr[], int a, int l, int r);

int main(void) {
    int count;
    scanf("%d", &count);

    int l = 1;
    int r = count;

    for(int i = 1; i <= count; i++) {
        scanf("%d", &arr[i]);
    }


    return 0;
}

int Max(int arr[], int a, int l, int r) {
    int amax = 1;
    for(int i = l; i <= r; i++) {
        if(arr[a] < arr[i]) {
            amax = 0;
        }
    }
    if(amax){
        return l r;
    }
}
