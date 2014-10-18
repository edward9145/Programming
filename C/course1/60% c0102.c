//ÊýÖµ±ä»»
#include<stdio.h>

int main()
{
    int a[3],i;
    for(i=0;i<3;i++)
    {
     scanf("%1d",&a[i]);
     if(a[i]>=0&&a[i]<=9)
      continue;
     else
     {
      printf("-1");
      return 0;
     }
    }
   if(a[2]!=0)
    for(i=2;i>=0;i--)
     printf("%d",a[i]);
   else
    if(a[1]!=0)
     for(i=1;i>=0;i--)
      printf("%d",a[i]);
    else
     printf("%d",a[0]); 
    
 return 0;
}
