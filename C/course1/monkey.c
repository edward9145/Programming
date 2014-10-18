#include<stdio.h>

int main()
{
   int i,n,m,q,r=0;
   scanf("%d%d%d",&n,&m,&q);
   for(i=2;i<=n;i++)
      r=(r+m)%i;
   printf("%d",(r+q)%n);
  // while(1);
   return 0;   
}
