//--------up.c
#include<stdio.h>

int maxlen(int c[],int num)
{
   int i,max;
   max=0;
   for(i=0;i<=num;i++)
      if(max<=c[i])
         max=c[i];
   return max;
}

int main()
{
   int ch[26]={0},num,max,i;
   char read;
      while((read=getchar())!='\n')
      {
         num=read-'a';
         ch[num]=maxlen(ch,num)+1;
      }
   max=0;
   //for(i=0;i<26;i++)
   //   printf("%d ",ch[i]);
   for(i=0;i<26;i++)
      if(max<=ch[i])
         max=ch[i];
   printf("%d\n",max);
   //while(1);
   return 0;
}
