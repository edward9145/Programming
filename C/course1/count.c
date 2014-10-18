#include<stdio.h>
int num[10001]={0};
int main()
{
   int n,i,tmp,max,maxnum;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&tmp);
      num[tmp]++;
   }
   max=0;
   for(i=0;i<n;i++)
   {
      if(max<num[i])
      {
         max=num[i];
         maxnum=i;   
      }
   }
   printf("%d",maxnum);
   //while(1);
   return 0;   
}
