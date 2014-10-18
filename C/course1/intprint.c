#include<stdio.h>

int main()
{
    int n[6],x,i,j;
    scanf("%d",&x);
    if(x>0&&x<=9)i=1;
    if(x>=10&&x<=99)i=2;
    if(x>=100&&x<=999)i=3;
    if(x>=1000&&x<=9999)i=4;
    if(x>=10000&&x<=99999)i=5;
    printf("%d\n",i);
    for(j=0;j<i;j++)
    {
        n[j]=x%10;
        x/=10;
    }
    for(j=i-1;j>=0;j--)
        printf("%d",n[j]);
    printf("\n");
    for(j=0;j<i;j++)
        printf("%d",n[j]);
    return 0;    
}
