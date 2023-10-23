//
// Created by wbh17 on 2023/10/22.
//
#include<stdio.h>
#include <string.h>
#include<stdbool.h>
int main()
{
    int n;
    char a[1010];
    int b[101];
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(65<=(int)a[i]&&(int)a[i]<=90)
        {
            b[(int)a[i]*2-128]++;
        }
        if(97<=(int)a[i]&&(int)a[i]<=122)
        {
            b[(int)a[i]*2-193]++;
        }
    }
    int max1=-1001;
    for(int i=1;i<=52;i++)
    {
        if(b[i]>max1)
            max1=b[i];
    }
    bool flag=true;
    int ans=0;
    while(max1!=0)
    {
        flag=false;
        for(int i=1;i<=52;i++)
        {
            if(b[i]!=0)
            {
                if (i % 2 == 1)
                {
                    if(b[i] >= max1)
                    {
                        flag = true;
                        printf("=");
                        if (max1 == 1) ans++;
                        if (b[i + 1]==0)
                        {
                            printf(" ");
                            if(max1==1) ans++;
                        }
                    }
                    else
                    {
                        if (b[i + 1]==0)
                        {
                            printf("  ");
                            if(max1==1) ans+=2;
                        }
                        else {
                            printf(" ");
                            if(max1==1) ans++;
                        }
                    }

                }
                if ( i % 2 == 0)
                {
                    if(b[i] >= max1)
                    { flag = true;
                        printf("=");
                        printf(" ");
                        if (max1 == 1) ans+=2;
                    }
                    else
                    {
                        printf("  ");
                        if(max1==1) ans+=2;
                    }
                }
            }
        }
        max1--;
        if(flag==true) printf("\n");
    }
    //printf("%d\n",b[2]);
    for(int i=1;i<=ans-1;i++)
    {
        printf("-");
    }
    printf("\n");
    for(int i=1;i<=52;i++)
    {
        if(b[i]!=0)
        {
            if(i%2==1&&b[i+1]!=0) printf("%c",(i-1)/2+97);
            else if(i%2==1) printf("%c ",(i-1)/2+97);
            else if(i%2==0) printf("%c ",(i)/2+64);
        }
    }
}