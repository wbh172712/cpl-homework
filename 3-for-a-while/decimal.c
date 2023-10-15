//
// Created by wbh17 on 2023/10/14.
//
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
    int len, N;
    scanf("%d %d", &len, &N);
    char sentence[10000];
    scanf("%s", sentence);

    int len_sentence = strlen(sentence);
    int result = 0;
    int a = 0;

    for (int i = 0; i < len_sentence; i++) {
        if (N <= 10 && (sentence[i] < '0' || sentence[i] > '0' + N - 1)){
            printf("Error");
            goto below;
        } else if (N > 10 && (N < sentence[i] - 'A' + 10)) {
            printf("Error");
            goto below;
        }
    }
    for (int i = 0; i < len_sentence; i++){
        if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
            a = sentence[i] - 'A' + 10;
        } else {
            a = sentence[i] - '0';
        }
        result = result + a * pow(N,len_sentence - i - 1);
    }
    printf("%d", result);
    below:
    return 0;
}
