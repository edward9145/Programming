//--------replace.c
#include<stdio.h>
#include<string.h>
char* alltolower(char *s)
{
   char *p;
   p=s;
   while(*s)*s=tolower(*s++);
   return p;
}

int main()
{
   char *find,*findtmp,findarray[100];
   char *replace,*replacepoint,replacearray[100],temp[100];
   char ch;
   int i,j,len,findlen,replacelen;
   gets(findarray);
      find=alltolower(findarray);
      findtmp=find;
      findlen=strlen(find);
   gets(replacearray);
      replace=replacearray;
      replacelen=strlen(replace);
   printf("%s\n%s",find,replace);
   
      freopen("filein.txt","r",stdin);
      freopen("fileout.txt","w",stdout);
      len=findlen-1;
      while((ch=getchar())!=EOF)
      {i=0;j=0;
         if(tolower(ch)==*find)
         {
            if(len==0){
               printf("%s",replace);
               ch=getchar();
            }
            if(len>0)
            {
               for(i=0;i<=len;i++)
               {
                  temp[i]=ch;
                  ch=getchar();
               }
 //              for(i=0;i<=len;i++)
   //               putchar(temp[i]);

               for(i=0;i<=len;i++)
                  if(*(find+i)==tolower(temp[i]))
                     j++;
               if(j!=len)
               {
                  printf("%s",replace);
               }
               else
               {
                  for(i=0;i<=len;i++)
                     printf("%c",temp[i]);
               }

                      //        printf("%",temp[i]);
               //printf("%s",replace);
               //replacepoint=&ch;
/*               while(tolower(ch)==*findtmp++&&*findtmp!='\0')
               {
                  temp[i++]=ch;
                  ch=getchar();
               }
               if(findtmp=='\0')
                  printf("%s",replace);
               else
                  printf("%s",temp);
*/
            }
         }
         putchar(ch);
      }
      fclose(stdin);
      fclose(stdout);

   while(1);
   return 0;
}
