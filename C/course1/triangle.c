#include<stdio.h>

void blank(int n)
{
   int i;
   for(i=1;i<=n;i++)
      printf(" ");
}

int main()
{
   int a[2][13]={0},n,i,j;
   scanf("%d",&n);
   a[0][0]=1;
   blank(2*n);
   printf("%4d\n",a[0][0]);
   for(i=1;i<=n;i++)
   {
      blank(2*(n-i));
      a[i%2][0]=1;
      a[i%2][i]=1;
      for(j=1;j<i;j++)
         a[i%2][j]=a[(i-1)%2][j]+a[(i-1)%2][j-1];
      for(j=0;j<=i;j++)
         printf("%4d",a[i%2][j]);
      printf("\n");
   }
   
//   while(1);
   return 0;   
}
