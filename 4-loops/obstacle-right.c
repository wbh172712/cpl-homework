//
// Created by wbh17 on 2023/10/22.
//
#include<stdio.h>
#include <math.h>
int main()
{
    int xa,ya,xb,yb,xc,yc;
    scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
    if((xa==xb&&xb==xc))
    {
        if(ya<yc&&yc<yb)
        {
            printf("%d\n",abs(ya-yb)+abs(xa-xb)+2);
            printf("L");
            for(int i=1;i<=abs(ya-yb);i++)
            {
                printf("U");
            }
            printf("R");
        }
        else if(yb<yc&&yc<ya)
        {
            printf("%d\n",abs(ya-yb)+abs(xa-xb)+2);
            printf("L");
            for(int i=1;i<=abs(ya-yb);i++)
            {
                printf("D");
            }
            printf("R");
        }
        else
        {
            printf("%d\n",abs(ya-yb)+abs(xa-xb));
            for(int i=1;i<=abs(yb-ya);i++)
            {
                if(yb>ya)printf("U");
                else printf("D");
            }
        }
    }
    else if((ya==yb&&yb==yc))
    {
        if(xa<xc&&xc<xb)
        {
            printf("%d\n",abs(ya-yb)+abs(xa-xb)+2);
            printf("U");
            for(int i=1;i<=abs(xb-xa);i++)
            {
                printf("R");
            }
            printf("D");
        }
        else if(xb<xc&&xc<xa)
        {
            printf("%d\n",abs(ya-yb)+abs(xa-xb)+2);
            printf("U");
            for(int i=1;i<=abs(xb-xa);i++)
            {
                printf("L");
            }
            printf("D");
        }
        else
        {
            printf("%d\n",abs(ya-yb)+abs(xa-xb));
            for(int i=1;i<=abs(xb-xa);i++)
            {
                if(xb<xa)printf("L");
                else printf("R");
            }
        }
    }
    else if(xa==xc||yb==yc)
    {
        printf("%d\n",abs(ya-yb)+abs(xa-xb));
        for(int i=1;i<=abs(xb-xa);i++)
        {
            if(xb>xa)printf("R");
            else printf("L");
        }
        for(int i=1;i<=abs(yb-ya);i++)
        {
            if(yb>ya)printf("U");
            else printf("D");
        }
    }
    else
    {
        printf("%d\n",abs(ya-yb)+abs(xa-xb));
        for(int i=1;i<=abs(yb-ya);i++)
        {
            if(yb>ya)printf("U");
            else printf("D");
        }
        for(int i=1;i<=abs(xb-xa);i++)
        {
            if(xb>xa)printf("R");
            else printf("L");
        }
    }
}