//--------sortwords.c
#include<stdio.h>
#include<string.h>
#define N 40

int wordcmp(char *a,char *b)
{
   while(*a++<=*b++)
   {
      if(*a>*b)return 1;
      if(*a=='\0')
      return 1;
   }
   return 0;   
}

int sameword(char *a,char *b)
{
   while(*a!='\0'&&*b!='\0')
   {
      if(*a==*b){a++;b++;}
      else return 0;
      if(*a=='\0'&&*b=='\0')return 1;  
   }
   return 0;
}

void sortasdic(char *list[],int num)
{
   int i,j,temp;
   char *tmp,*a,*b;
   
   i=0;
   for(j=0;j<num-j;j++)
   {
      
   }
}

int main(int argc,char* argv[])
{
    FILE *fin,*fout;
    int i=0,j,num,exist[N]={0};
    char sort[N][N],ch;
    char *dic[N],*tmp;
    freopen(argv[1],"r",stdin);
   // freopen(argv[2],"w",stdout);
    while(1)
    {
      scanf("%s",sort[i++]);
      ch=getchar();
      if(ch==' ')ch=getchar();
      else break;
   }
   num=i;
   i=sameword(&sort[1][0],&sort[6][0]);
   printf("%d",i);
   
  
    fclose(stdin);
    fclose(stdout); 
    return 0;
}
