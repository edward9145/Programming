//-------matrix.c
#include<stdio.h>
#define N 11
int main()
{
    int a[N][N],b[N][N],i,j,n;
    char op='+';
    scanf("%d",&n);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        a[i][j]=0,b[i][j]=0;  
    do
    {
      for(i=0;i<n;i++)
      {  for(j=0;j<n;j++)
        {  scanf("%d",&b[i][j]);
           if(op=='+')
             a[i][j]+=b[i][j];
            if(op=='-')
             a[i][j]-=b[i][j];
        }
      }
     while(1)
     {
      op=getchar();
      if(op=='+'||op=='-'||op=='#')
        break;
     }
    }while(op!='#');
    
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        printf("%5d",a[i][j]);
      printf("\n");
    }  
  //  while(1);
    return 0;
      
}
