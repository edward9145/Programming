//-------libianxing.c--------
#include<stdio.h>
void star(int x)
{
  int i;
  for(i=1;i<=x;i++)
    printf("*");  
}

void blank(int x)
{
  int i;
  for(i=1;i<=x;i++)
    printf(" ");
}

void cr()
{
  printf("\n");  
}


int main()
{
  int n,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
      blank(n-i);
      if(i==1)
      {
        star(n);
        cr();
        continue;
      }
      else
      star(1);
      blank(n+(i-2)*2);
      star(1);
      cr();
  }
  for(i=n-1;i>=1;i--)
  {
      blank(n-i);
      if(i==1)
      {
        star(n);

        continue;
      }
      else
      star(1);
      blank(n+(i-2)*2);
      star(1);
      cr();
  }  
  return 0;  

}

