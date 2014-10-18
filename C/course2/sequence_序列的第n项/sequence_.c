#include<stdio.h>
int digitSum(int);

int main(){
   int a[1002],k,n;
   int i;
   int tmp;
   //freopen("sequence.in","r",stdin);
   //freopen("sequence.out","w",stdout);
   while(1){
   scanf("%d%d%d",&a[1],&k,&n);
   for(i=1;i<=n;i++){
      for(tmp=a[i]+1;
         digitSum(tmp) != digitSum(k*a[i]);
         tmp++);
      a[i+1]=tmp;
      printf("%d %d\n",a[i],digitSum(a[i]));
   }
   printf("%d\n",a[n]);
}
   system("pause");
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
