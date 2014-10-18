#include<stdio.h>
int isPrime(int n){
   int i;
   for(i=2;i*i<=n;i++){
      if(n%i==0)
         return 0;
   }
   return 1;
}
int a[2][10]={0};
int b[4]={2,3,5,7};
int main()
{
   int k,m,n,i,j,a_len;
   int N,nPower=10;   
   scanf("%d",&N);
   for(k=0;k<4;k++){
      a[0][0]=b[k];
      a_len=1;
      for(n=1;n<N;n++){
         //nPower=10;
         j=0;
         for(i=0;i<a_len;i++){
            for(m=a[(n+1)%2][i]*nPower+1;m<(a[(n+1)%2][i]+1)*nPower;m+=2){
               if(isPrime(m)) a[n%2][j++]=m;
            }
         }
         a_len=j;
      }
      
      for(i=0;i<a_len;i++)
         printf("%d\n",a[(n+1)%2][i]);
   }
   
   while(1);
   return 0;
}
