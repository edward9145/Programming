#include<stdio.h>
int datetoday(int y,int m,int d)
{
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31},i,n=0;
    if(y/100==0)
        y/=100;
    if(y%4==0)
        month[1]++;
    for(i=0;i<m-1;i++)
        n+=month[i];
    n+=d;
    return n;
}

int main()
{
    int yy,mm,dd,n;
    scanf("%d %d %d",&yy,&mm,&dd);
    n=datetoday(yy,mm,dd);
    printf("%d",n);
    return 0;    
}
