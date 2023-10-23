//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
int main(void){
    int N;
    scanf("%d", &N);

    int number[100000];

    for (int i = 0; i < N; i++) {
        scanf("%d", &number[i]);

        int content[500000];
        for (int j = 0; j < number[i]; j++) {
            scanf("%d", &content[j]);
        }

        int result = 1;
        for(int j = 0; j < number[i] - 1; j++) {
            if (content[j] > content[number[i] - 1]) {
                result = 0;
            }
        }
        if (result == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }

    }

    return 0;
}