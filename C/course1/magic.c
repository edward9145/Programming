//------magic.c
#include<stdio.h>
void out(int x)
{
      printf("%d",x);
}

void cr()
{
  printf("\n");
}

int min(int a,int b)
{
  return a<b?a:b;  
}


int main()
{
    int n,i,j,t;
    scanf("%d",&n);
    n=2*n-1;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
        t=min(i,min(j,min(n+1-i,n+1-j)));
        out(t);
      }      
      cr();
    }
    
    return 0;  
}
