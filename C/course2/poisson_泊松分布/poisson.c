#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_INTER 1e280
#define MIN_INTER 1e-280
/*
double Possion(double m,int k)
{
    double p;
    int i;
    
    p=(float)k*log(m)-m;
    for(i=2;i<=k;i++){
        p-=log(i);
    }
    return exp(p);
}
*/
double poisson(double m,int k)
{
   double x=1.0;
   int em,mk,nk;
   em=mk=nk=0;
   while(em<m||mk<k||nk<k){
      while(mk<k&&x<MAX_INTER){
         x*=m;
         mk++;
      }
      if(x<MIN_INTER)
         return 0.0;
      while(nk<k&&x>MIN_INTER){
         nk++;
         x/=nk;
      }
      while(em<m&&x>MIN_INTER){
         x/=M_E;
         em++;
      }
   }
   return x;
}
int main()
{
    int m,k;
    double P;
    freopen("poisson.in","r",stdin);
    freopen("poisson.out","w",stdout);
    scanf("%d%d",&m,&k);
    P=poisson((double)m,k);
    printf("%e",P);
    //system("pause");
}
