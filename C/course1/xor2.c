#include<stdio.h>

int main()
{
   char ch;
   int a[40],i,m,tmp;
   tmp=0;i=0;
      while((ch=getchar())!=EOF)
      {
         if(ch>='0'&&ch<='9')
            tmp=tmp*10+(ch-'0');   
         if(ch==' '||ch=='\n'){ 
            a[i++]=tmp;
            tmp=0;
         }
      }
   m=i;
      for(i=0;i<m;i++)
         printf("%d ",a[i]);
   
   return 0;   
}
