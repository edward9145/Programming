//--------sortwords.c
#include<stdio.h>
#include<string.h>
#define N 40
//--------compare 2 word return a value to decide whether swap or not
int wordcmp(char *a,char *b)
{
   while(*a!='\0'&&*b!='\0')
   {
      if(*a<*b)return 1;
      if(*a>*b)return 0;
      a++;b++;
      
   }
   if(*a=='\0')return 1;
   else return 0;
}
//---------------------------
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

int main(int argc,char* argv[])
{
    FILE *fin,*fout;
    int i=0,j,num,exist[N]={0};
    char sort[N][N],ch;
    char *dic[N],*tmp;
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
    while(1)
    {
      scanf("%s",sort[i++]);
      ch=getchar();
//      if(ch==' ')ch=getchar();
  //    else if(ch==EOF)break;
      if(ch==EOF)break;
      else continue;
   }
   num=i;
   for(i=0;i<num;i++)
   {
      for(j=i+1;j<num;j++)
      {
         if(sameword(&sort[i][0],&sort[j][0])==1)
         {
            exist[j]=1;break;
         }
      }   
   }
   
   j=0;
   for(i=0;i<num;i++)
   {
      if(exist[i]==0)
         {dic[j++]=sort[i];}
   }
   //for(i=0;i<j;i++)printf("%s ",dic[i]);
   //putchar(10); 
   num=j;
   for(i=0;i<num;i++)
   {
      for(j=num-1;j>i;j--)
      {
         if(wordcmp(dic[j],dic[j-1])==1)
         {
            tmp=dic[j];
            dic[j]=dic[j-1];
            dic[j-1]=tmp;   
         }  
      }
   }
    //swappointer(&dic[j],&dic[j-1]);
   //swappointer(&dic[1],&dic[num-2]);
   //sortasdic(dic,num);
   
   for(i=0;i<num;i++)printf("%s ",dic[i]);

    fclose(stdin);
    fclose(stdout); 
    return 0;
}
