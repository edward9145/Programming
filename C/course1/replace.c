//--------replace.c
#include<stdio.h>
char* alltolower(char *s)
{
   char *p;
   p=s;
   while(*s)
      *s=tolower(*s++);
   return p;
}

int main()
{
   char *find,*findtmp,findarray[100];
   char *replace,replacearray[100],temp[100];
   char ch;
   int i,j,len,findlen,replacelen;
   scanf("%s",findarray);     //gets(findarray);
      find=alltolower(findarray);
      findtmp=find;
   scanf("%s",replacearray);  //gets(replacearray);
      replace=replacearray;

   freopen("filein.txt","r",stdin);
   freopen("fileout.txt","w",stdout);
      while((ch=getchar())!=EOF)
      {
         i=0;
         while(tolower(ch)==*(find+i))
         {
            temp[i++]=ch;
            ch=getchar();
         }  
         temp[i]='\0';
         
         if(*(find+i)=='\0')
            printf("%s",replace);
         else
            printf("%s",temp);
            
         if (ch!=EOF) putchar(ch);
      }
      fclose(stdin);
      fclose(stdout);
    //  while(1);
      return 0;
}
