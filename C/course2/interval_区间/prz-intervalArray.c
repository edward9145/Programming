#include<stdio.h>
char interval[2000001]={0};

int main(){
   freopen("prz.in","r",stdin);
   freopen("prz.out","w",stdout);
   int n;
   int a,b,i,j;
   int min=1000001,max=0;
   scanf("%d",&n);
   for(i=0;i<n;i++){
      scanf("%d %d",&a,&b);
      if(min>a) min=a;
      if(max<b) max=b;
      for(j=a;j<b;j++){
         
            interval[j]=1;
      }
      if(interval[j]!=1)
         interval[b]=2;
   }
//for(i=min;i<=max;i++) printf("%d ",interval[i]); printf("\n");
   printf("%d",min);
   for(i=min+1;i<=max;i++){
      if(interval[i]==2){
         if(interval[i-1]!=1)
            printf("%d %d\n",i,i);
         else
            printf(" %d\n",i);
      }
      if(interval[i]==1&&interval[i-1]!=1)
         printf("%d",i);
   }
   //while(1);
   return 0;
}
