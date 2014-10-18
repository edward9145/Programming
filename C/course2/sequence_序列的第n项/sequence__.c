#include<stdio.h>

int digitSum(int x);
int main(){
   int a[1002],k,n;
   int i;
   freopen("sequence.in","r",stdin);
   freopen("sequence.out","w",stdout);
   scanf("%d%d%d",&a[1],&k,&n);
   for(i=1;i<=n;i++){
      int tmp=a[i];
      while(tmp++){
         if(digitSum(tmp)==digitSum(k*a[i])){
            break;
         }
      }
      a[i+1]=tmp;
   }
   printf("%d\n",a[n]);
   //system("pause");
   return 0;
}

int digitSum(int x){
   int i,sum=0;
   while(x!=0){
      sum+=x%10;
      x/=10;
   }
   return sum;
}
