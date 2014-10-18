#include<stdio.h>

int main()
{
   int N;
   scanf("%d",&N);
   int i,j,k,n,a[9][9];
   for(i=0;i<N;i++){
      for(j=0;j<N;j++){
         a[i][j]=0;
      }
   }
   i=0;j=0;n=0;k=1;
   for(k=1;k<N*N;n++){
      for(j=n;j<N-1-n;j++) a[i][j]=k++;
      for(i=n;i<N-1-n;i++) a[i][j]=k++;
      for(;j>n;j--) a[i][j]=k++;
      for(;i>n;i--) a[i][j]=k++;
      i++;j++;
   }
   if(N%2==1)a[i][j]=N*N;
   
   for(i=0;i<N;i++){
      for(j=0;j<N;j++){
         printf("%5d",a[i][j]);
      }
      printf("\n");
   }
   
   //getchar();
   //getchar();
   return 0;
}
