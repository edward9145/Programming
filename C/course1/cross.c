#include<stdio.h>
typedef struct
{
   char w[30];
   int l;
}word;

void deldot(char *x)
{
   do
   { if(*x=='.')*x='\0';
   }while(*x++!='\0');
}
int filter(char *x)
{
   if(strcmp(x,"a")==0)return 1;
   if(strcmp(x,"an")==0)return 1;
   if(strcmp(x,"and")==0)return 1;
   if(strcmp(x,"the")==0)return 1;
   if(strcmp(x,"\0")==0)return 1;
   if(*x<'A')return 1;
   else return 0;
}

void swap(word *x,word *y)
{
   word t;
   t=*x;*x=*y;*y=t;   
}

int main()
{
   word a[200];
   int i,j,len,line;
   char ch='\0';
   freopen("crossin.txt","r",stdin);
   freopen("crossout.txt","w",stdout);
   i=0;
   line=1;
   while(ch!=EOF)//(a[i].w!=NULL)&&
   {
      scanf("%s",a[i].w);
      ch=getchar();
      deldot(a[i].w);
      if(filter(a[i].w))continue;
      a[i].l=line;
      if(ch=='\n')line++;
      i++;
   }
len=i;   
   for(i=0;i<len;i++)
      for(j=len-1;j>i;j--)
         if(strcmp(a[j].w,a[j-1].w)<0)
            swap(&a[j],&a[j-1]);
            
if(len>0)printf("%s:%d",a[0].w,a[0].l);
   for(i=1;i<len;i++)
   {
      if(strcmp(a[i].w,a[i-1].w)==0)
      {
         if(a[i].l!=a[i-1].l)
            printf(",%d",a[i].l);
      }
      else
         printf("\n%s:%d",a[i].w,a[i].l);
   }
//   while(1);
   return 0;   
}
