#include<stdio.h>
#define N 80

int c[N]={0};
void output(int a[],int len)
{
   int i;
   for(i=0;i<len;i++)printf("%d",a[i]);
}

void swap(int *x,int *y)
{
   int t;
   t=*x;*x=*y;*y=t;
}
void reverse(int a[],int len)      
{
   int i;
   for(i=0;i<len-i;i++)
      swap(&a[i],&a[len-1-i]);
}

int minus(int a[],int b[],int lena,int lenb)
{
   int ab[N]={0};
   int i,j,len,take;
   len=lena>lenb?lena:lenb;
   take=0;
   for(i=0;i<len;i++)
   {
      if(a[i]-b[i]-take<0)
      {
         ab[i]=a[i]+10-b[i]-take;
         take=1;
      }
      else
      {
         ab[i]=a[i]-b[i]-take;
         take=0;
      }
   }
   if(take==1)return -1;
   for(i=0;i<len;i++)c[i]=ab[i];
   for(j=len-1;ab[j]==0;j--)
      if(c[j]==0)len--;
   if(len==0)len=1;
   return len;
}

int main()
{
   int a[N]={0},b[N]={0},i,j;
   int lena,lenb,len,taken=0;
   char ch,sgn='\0';;
   i=0;j=0;
   do{
      ch=getchar();
      if(ch=='\n')break;
      a[i++]=ch-'0';
   }while(ch!='\n');
   do{
      ch=getchar();
      if(ch=='\n')break;
      b[j++]=ch-'0';
   }while(ch!='\n');
   lena=i;lenb=j;
   
   reverse(a,lena);
   reverse(b,lenb);
  // output(a,lena);putchar(10);output(b,lenb);
   len=minus(a,b,lena,lenb);
   if(len==-1)
   {
      len=minus(b,a,lenb,lena);
      sgn='-';
      putchar(sgn);
   }
   reverse(c,len);
   output(c,len);
 //  while(1);
   return 0;   
}
