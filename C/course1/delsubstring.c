#include<stdio.h>

char* cat(char *p,char *s)
{
   int i=0;
   char a[1000];
   while(a[i++]=*(p++))if(*p=='\0')break;
   while(a[i++]=*(s++));
//   a[i]='\0';   
//   puts(a);
   return a;
}

int main()
{
   char str[1000],rep[1000],*p,*s;
   scanf("%s",str);
   getchar();
   gets(rep);
   p=cat(str,rep);
   
   
   printf("%s",p);
   
   //while(1);
   return 0;   
}
