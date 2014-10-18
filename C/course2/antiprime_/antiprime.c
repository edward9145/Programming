#include<stdio.h>
int prime[]={2,3,5,7,11,13,17,19,23,29,31};
int divisors(int p)
{
   int i,j;
   for(j=0,i=2;i*i<=p;i++)
      if(p%i==0)
         j++;
   return j+1;   
}

void antiprime(int x){
   /*
   int m,p,k,n = 0,num = 0,t;
   
   for(p=0,k=1;k<=sqrt(x);p++)
      k*=prime[p];
   m = (k/= prime[p-1]);
   while(k<=x){
      t=divisors(k);
      if(t>n)
         n = t,num = k;
       k+=m;
   }
   printf("%d \n",k);
   return;
   */
   int i,j,n;
   int tmp=1,tmp_num=1;
   for(i=1;i<=x;i++){
      n=divisors(i);
      if(n>tmp_num){
         tmp_num=n;
         tmp=i;
      }
   }
   printf("%d\n",tmp);
}


int main()
{
   int n;
   int tmp=1;
   int i,j;
   freopen("antiprime.in","r",stdin);
   freopen("antiprime.out","w",stdout);
   scanf("%d",&n);
   antiprime(n);
   return 0;
}
