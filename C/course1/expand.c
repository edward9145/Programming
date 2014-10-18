#include<stdio.h>
void expand(char head,char tail)
{
    if(head<tail)
    {
      while(head<tail)
        printf("%c",++head);
    }
    else
      printf("-%c",tail);
}

int main()
{
    char ch,head,tail;
    while((ch=getchar())!=EOF)
    {
     // if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
      if(ch=='-')
      {
        tail=getchar();
        expand(head,tail);
        head=tail;
      }
      else
      {
        head=ch;
        putchar(head);
      }
   //   else putchar(ch);
    }
    return 0;  
}
