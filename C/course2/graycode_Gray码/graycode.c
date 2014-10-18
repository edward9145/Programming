#include<stdio.h>
int main(){
   int i,gi;
   char c[51],g[51],b[51];
      freopen("graycode.in","r",stdin);
   while(gets(c)){
      if(c[1]=='g'){
         for(i=0;c[2+i]!='\0';i++)
            g[i]=c[2+i];
         g[i]='\0';
         b[0]=g[0];
         for(i=1;g[i]!='\0';i++)
            b[i]=(g[i]-'0')^(g[i-1]-'0')+'0';
         b[i]='\0';
      }
      else if(c[1]=='b'){
         for(i=0;c[2+i]!='\0';i++)
            g[i]=c[2+i];
         g[i]='\0';
         b[0]=g[0];
         for(i=1;g[i]!='\0';i++)
            b[i]=(g[i]-'0')^(b[i-1]-'0')+'0';
         b[i]='\0';
      }
      else{
         for(i=0;c[i]!='\0';i++)
            g[i]=c[i];
         g[i]='\0';
         b[0]=g[0];
         for(i=1;g[i]!='\0';i++)
            b[i]=(g[i]-'0')^(b[i-1]-'0')+'0';
         b[i]='\0';
      }
      puts(b);
      //putchar(10);
   }
      while(1);
   system("pause");

   return 0;
}
