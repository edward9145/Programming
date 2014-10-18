#include<stdio.h>
int c[20],num,bigger;

void add(int a[],int b[],int i,int j)
{
     int carry,m,n;
     m=i?j:i>j;
     m=19-m;
     carry=0;
     for(n=20;n>=m;n--)
     {
      if(a[n]+b[n]+carry>=10)
      {
       c[n]=(a[n]+b[n]+carry)%10;
       carry=1;                       
      }
      else
      {
       c[n]=a[n]+b[n]+carry;
       carry=0;
      }                
     }
     num=m;
}

main()
{
      int a[10],b[10],i,j,n;
      for(i=0;i<10;i++)
      {a[i]=0;b[i]=0;}
      
      char ch;
      for(i=9;i>=0;i--)
      {
       scanf("%c",&ch);
       if(ch==10)break;  
       a[i]=ch-48;
      }
      ch=0;
      for(j=9;j>=0;j--)
      {
       scanf("%c",&ch);
       if(ch==10)break;  
       b[j]=ch-48;
      }
      printf("\na=");
      for(n=9;n>i;n--)
       printf("%d",a[n]);
      printf("\nb=");
      for(n=9;n>j;n--)
       printf("%d",b[n]);
 
      i=9-i;
      j=9-j;
     printf("\n\na+b=");
      add(a,b,i,j);
      for(n=20;n>num;n--)
       printf("%d",c[n]);
      getchar();     
}
