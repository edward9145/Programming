#include<stdio.h>

int main(){
   freopen("invertsub.in","r",stdin);
   freopen("invertsub.out","w",stdout);
   char str[60];
   char cmp[60];
   char c;
   int i,j;
   for(i=0;(c=getchar())!='\r'&&c!='\n';str[i++]=c);
   if(c=='\r') getchar();
   str[i]='\0';
   for(i=0;(c=getchar())!='\r'&&c!='\n';cmp[i++]=c);
   if(c=='\r') getchar();
   cmp[i]='\0';
   
   for(i=0;i<strlen(str)&&str[i]!='\0';i++){
      if(str[i]==cmp[0]){
         for(j=0;j<strlen(cmp)&&cmp[j]!='\0';j++){
            if(str[i+j]!=cmp[j]) break;
         }
         if(j==strlen(cmp)){
            do{ printf("%c",cmp[--j]);
            }while(j>0);
            for(i=i+strlen(cmp);str[i]!='\0';printf("%c",str[i++]));
         }
         else{printf("%c",str[i]);}
      }
      else{
         printf("%c",str[i]);
      }
   }
   printf("\n");
   //while(1);
   return 0; 
}
   
