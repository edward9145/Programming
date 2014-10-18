#include<stdio.h>

int main()
{
   int i,j,a[100][100]={0},k,num,n;
   scanf("%d",&n);
   freopen("file.out","w",stdout);
   
   num=1;
   i=0;j=0;
   for(k=1;k<=n;k++)
   {  i++;j++;
      for(;j<=n-k;j++)a[i][j]=num++;   
      for(;i<=n-k;i++)a[i][j]=num++;
      for(;j>k;j--)a[i][j]=num++;
      for(;i>k;i--)a[i][j]=num++;
      if((k==n)&&(k%2==1))a[(k+1)/2][(k+1)/2]=num;
   }
   
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
         printf("%5d",a[i][j]);
       printf("\n");   
   }
   fclose(stdout);
  // while(1);
   return 0;   
}
