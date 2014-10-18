#include<stdio.h>
int isPrime(int x)
{
    int n=2;
    if(x==1)return 0;
    while(n<x)
    {
        if(x%n==0)return 0;
        n++;
    }
    if(n==x)return 1;        
}

int main()
{
    int a,b[100000],i,j;
    scanf("%d",&a);
    if(a<=1)
    {
        printf("no");
        return 0;
    }
    i=0;
    if(isPrime(a)==0)
    {
        printf("no");
        return 0;
    }
    while(a>0)
    {
       b[i]=a%10;
       i++;
       a/=10;
    }

    j=0;
    while(j<i)
    {
        a*=10;
        a+=b[j];
        j++;
    }
    
 //   printf("%d",a);
    if(isPrime(a)==0)
    {
        printf("no");
        return 0;
    }
    else
        printf("yes");
    return 0;    
}
