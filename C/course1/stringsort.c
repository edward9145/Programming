//--------stringsort.c
#include<stdio.h>

int main()
{
   int a[256]={0},i;
   char ch;
      while((ch=getchar())!=EOF)
       if(ch>=0&&ch<=255)
         a[ch]=1;
      for(i=0;i<256;i++)
      {  if(a[i]==1)
            printf("%c",i);      
      }
  //    while(1);
   return 0;   
}
