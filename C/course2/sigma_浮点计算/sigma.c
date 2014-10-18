#include<stdio.h>
#define DECIMAL 2000

int main(){
   int k,x,m,n;
   int i,j;
   long long integer=1;
   long long power=1;
   double sum=0.0;
   double xm=1.0;
   char decimal[DECIMAL]={0};
   freopen("sigma.in","r",stdin);
   scanf("%d%d%d%d",&k,&x,&m,&n);
   
   for(i=0;i<m;i++) xm/=(double)x;
   if(x!=1) sum=((double)xm - 1.0) / (double)(1-x) * (double)k;
   else sum=(double)k  * (double)m;
   
   for(i=1;i<=n;i++){
      power*=x;
      integer+=power;
   }
   integer*=k;
   integer+=sum;
/*小数处理*/   
   sum -= (long long)sum;
   sprintf(decimal,"%.14f",sum);
   printf("%lld%s\n",integer,decimal+1);
//while(1);
   return 0;
}
