#include<stdio.h>
typedef struct{
   char *str;
   int priority;
}Formula;

Formula stack[100];
int top=-1;

Formula link(Formula a,char mark,Formula b,int prior){
   Formula f;
   int a_len=strlen(a.str);
   int b_len=strlen(b.str);
   f.str=(char*)malloc(sizeof(char)*(a_len+b_len+8));
   if(a.priority < prior){
      f.str[0]='('; f.str[1]='\0';
      strcat(f.str,a.str);
      f.str[a_len+1]=')'; f.str[a_len+2]=mark; f.str[a_len+3]='\0';
   }
   else{
      f.str[0]='\0';
      strcat(f.str,a.str);
      f.str[a_len]=mark; f.str[a_len+1]='\0';
   }
   int f_len=strlen(f.str);
   if(b.priority <= prior){
      f.str[f_len]='('; f.str[f_len+1]='\0';
      strcat(f.str,b.str);
      f.str[f_len+b_len+1]=')'; f.str[f_len+b_len+2]='\0';
   }
   else{
      strcat(f.str,b.str);
      f.str[f_len+b_len]='\0';
   }
   return f;
}

int main(){
   char tmp[20];
   char c=' ';
   while(c==' '){
      scanf("%s%c",tmp,&c);
      switch(tmp[0]){
         case '+':
            //if(top<1) while(1);
            if(tmp[1]!='\0'){
                if(top==-1){
                  stack[++top].str=(char*)malloc(sizeof(char)*(strlen(tmp)+1));
                  strcpy(stack[top].str,tmp);
                  stack[top].priority=4;
               }
               else{
                  stack[++top].str=(char*)malloc(sizeof(char)*(strlen(tmp)+4));
                  stack[top].str[0]='('; stack[top].str[1]='\0';
                  strcat(stack[top].str,tmp);
                  stack[top].str[strlen(tmp)+1]=')';
                  stack[top].str[strlen(tmp)+2]='\0';
                  stack[top].priority=4;
               }
            }
            else{
               stack[top-1]=link(stack[top-1],'+',stack[top],1);
               top=top-1;
               stack[top].priority=1;
            }
            break;
         case '-':
            //if(top<1) while(1);
            if(tmp[1]!='\0'){
                if(top==-1){
                  stack[++top].str=(char*)malloc(sizeof(char)*(strlen(tmp)+1));
                  strcpy(stack[top].str,tmp);
                  stack[top].priority=4;
               }
               else{
                  stack[++top].str=(char*)malloc(sizeof(char)*(strlen(tmp)+4));
                  stack[top].str[0]='('; stack[top].str[1]='\0';
                  strcat(stack[top].str,tmp);
                  stack[top].str[strlen(tmp)+1]=')';
                  stack[top].str[strlen(tmp)+2]='\0';
                  stack[top].priority=4;
               }
            }
            else{
               stack[top-1]=link(stack[top-1],'-',stack[top],1);
               top=top-1;
               stack[top].priority=1;
            }
            break;
         case '*':
            //if(top<1) while(1);
            stack[top-1]=link(stack[top-1],'*',stack[top],2);
            top=top-1;
            stack[top].priority=2;
            break;
         case '/':
            if(top<1){
               printf("%s\n",stack[top].str); return 0;
            }
            stack[top-1]=link(stack[top-1],'/',stack[top],2);
            top=top-1;
            stack[top].priority=2;
            break;
         default:
            stack[++top].str=(char*)malloc(sizeof(char)*(strlen(tmp)+1));
            strcpy(stack[top].str,tmp);
            stack[top].priority=4;      
            break;
      }
      //printf("top=%d, %s ~(%d)\n",top,stack[top].str,stack[top].priority);
   }
   printf("%s\n",stack[top].str);
   
   system("pause");
   return 0;
}
