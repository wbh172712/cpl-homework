//
// Created by wbh17 on 2023/11/13.
//
#include <stdio.h>

int result[1000];

void findDecomposition(int n, int min, int nFound) {
    if (n == 0) {
        for (int i = 0; i < nFound; i++) {
            printf("%d ", result[i]);
        }
        printf ("\n");
    }

    if(nFound == 0) {
        min = 1;
    } else {
        min = result[nFound - 1];
    }

    if (n < min) {
        return;
    }
    
    for(int i = min; i <= n; i++) {
        result[nFound] = i;
        findDecomposition(n - i, min, nFound + 1);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    findDecomposition(n, 1, 0);

    return 0;
}
