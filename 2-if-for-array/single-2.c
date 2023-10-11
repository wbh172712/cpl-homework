//
// Created by wbh17 on 2023/10/10.
//
#include <stdio.h>
int main(void)
{
    int a1[100000];
    int a2[100000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int a = 0;
        scanf("%d", &a);
        a1[i] = a;
        a2[a1[i]]++;
    }
    for (int m = 0; m < 2 * n - 1; m++)
    {
        if (a2[a1[m]] == 1)
        {
            printf("%d", a1[m]);
        }
    }
    return 0;
}