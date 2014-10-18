//ÇóºÍ
#include<stdio.h>
int sum(int n)
{
    int i,j,s=0;
    for(i=1;i<=n;i++)    
     for(j=1;j<=i;j++)
      s+=j;
    return s;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",sum(n));
    return 0;    
}
