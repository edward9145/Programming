#include<stdio.h>
int existChar(char str[],char c);
int isReal(char str[]);
int isInteger(char str[]);
int isFloat(char str[]);
void init(char b[],char s[],char a[],char c);

int main(){
   char num[100];
   char beforE[50],afterE[50];
   freopen("real.in","r",stdin);
   freopen("real.out","w",stdout);

   scanf("%s",num);
   if(existChar(num,'E')){
      init(beforE,num,afterE,'E');
      if(isReal(beforE) && isInteger(afterE))
         printf("Format2\n");
      else
         printf("Wrong\n");
   }
   else{
      if(isReal(num))
         printf("Format1\n");
      else
         printf("Wrong\n");
   }
   
   return 0;
}

int existChar(char str[],char c)
{
   int i;
   for(i=0;i<strlen(str)-1;i++)
      if(str[i]==c)
         return i;
   return 0;
}

int isReal(char str[])
{
   char beforeD[50],afterD[50];
   if(existChar(str,'.')){
      init(beforeD,str,afterD,'.');
      if(isInteger(beforeD) && isFloat(afterD))
         return 1;
      else
         return 0;
   }
   else{
      if(isInteger(str))
         return 1;
      else
         return 0;
   }
}

int isInteger(char str[])
{
   int i;
   if(str[0]>'0'&&str[0]<='9'){
      for(i=1;str[i]>='0'&&str[i]<='9'&&str[i]!='\0';i++);
      if(str[i]=='\0') return 1;
      else return 0;
   }
   else if(str[0]=='+'||str[0]=='-'){
       if(str[1]>'0'&&str[1]<='9'){
         for(i=2;str[i]>='0'&&str[i]<='9'&&str[i]!='\0';i++);
         if(str[i]=='\0') return 1;
         else return 0;
      }
   }
   return 0;
}

int isFloat(char str[])
{
   int i=0;
   while(str[i]>='0'&&str[i]<='9') i++;
   if(str[i]=='\0') return 1;
   else return 0;
}

void init(char b[],char s[],char a[],char c)
{
   int i=0;
   while(s[i]!=c){ b[i]=s[i]; i++;}
   b[i]='\0';
   int j=0;
   while(s[i+1+j]!='\0'){ a[j]=s[i+1+j]; j++;}
   a[j]='\0';
}
