#include<stdio.h>
int loop(int x)
{
    int a=x,b[1000],i,j;
    i=0;
    while(a>0)
    {
       b[i++]=a%10;
       a/=10;
    }
    j=0;
    while(j<i)
    {
        a*=10;
        a+=b[j++];
    }
    if(x==a)return 1;
    else return 0;
}

int main()
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++)
      if(loop(i)==1)
        printf("%d\n",i);
    
    return 0;    
}
