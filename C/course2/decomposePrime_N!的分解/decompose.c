#include<stdio.h>
int P[4000]={0};
int K[4000]={0};

int isPrime(int n)
{
   int i;
   for(i=2;i*i<=n;i++){
      if(n%i==0)
         return 0;
   }
   return 1;
}

int generatePrime(int n)
{
   int i,j=0;
   for(i=2;i<=n;i++)
      if(isPrime(i))
         P[j++]=i;
   P[j]=n+1;
   return j-1;
}

int main(){
   int N;
   int i,m;
   int primeNum;
   scanf("%d",&N);
   primeNum=generatePrime(N);
   
   for(i=0;i<=primeNum;i++){
      m=N;
      while(m>1){
         K[i]+=m/P[i];
         m/=P[i];
      }
      if(K[i]>1)
         printf("%d^%d*",P[i],K[i]);
      else if(K[i]==1){
         if(i<primeNum) printf("%d*",P[i]);
         else printf("%d",P[i]);
      }
      else
         printf("%d*",P[i]);  
   }
   
   //while(1);
   return 0;
}
