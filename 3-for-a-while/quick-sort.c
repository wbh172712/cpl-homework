//
// Created by wbh17 on 2023/10/15.
//
#include <stdio.h>
int main(void) {
    int number, k;
    scanf("%d %d", &number, &k);

    int array[100000];
    for (int i = 0; i < number; i++) {
        scanf("%d", &array[i]);
    }

    int pivot = array[k - 1];
    int forward = 0;
    int backward = number - 1;

    while (forward < backward) {
        while(array[forward] < pivot) {
            forward++;
        }
        while(array[backward] >= pivot) {
            backward--;
        }
        int change_1;
        if (forward < backward) {
            change_1 = array[forward];
            array[forward] = array[backward];
            array[backward] = change_1;
            if(forward == k - 1) {
                k = backward + 1;
            }
        }
    }
    int change_2;
    change_2 = array[forward];
    array[forward] = array[k - 1];
    array[k - 1] = change_2;
    for (int i = 0; i < number; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}