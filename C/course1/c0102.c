#include<stdio.h>
main()
{
    int a,b,c,x;
    scanf("%d",&x);
    if(x>=100&&x<=999)    
    {
        a=x/100;
        b=(x%100)/10;
        c=x%10;
        x=c*100+b*10+a;
        printf("%d",x);
    }
    else
        printf("-1");
}
