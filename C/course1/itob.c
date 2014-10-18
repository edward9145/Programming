//---------itob.c
#include<stdio.h>
/*
void itob(char s[],int n,int b)
{
   char *num;
   int i;
      for(i=0;n/b!=0;i++)
      {
         if(n%b>=10)
            s[i]=n%b+'a';
         else
            s[i]=n%b+'0';
      }  
}
*/
int main()
{
   int n,b,i,j;
   char s[100],sgn='\0';
   scanf("%d%d",&n,&b);
      if(n<0){sgn='-';printf("%c",sgn);n*=-1;}
      
      for(i=0;n!=0;i++)
      {
         if(n%b>=10)
            s[i]=n%b-10+'a';
         else
            s[i]=n%b+'0';
         n/=b;
      } 
   
   for(j=i-1;j>=0;j--)
      printf("%c",s[j]);
  // while(1);
   return 0;   
}
