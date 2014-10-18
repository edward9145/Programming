#include<stdio.h>
#define MAX 1000
int factor[MAX]={0};
int tmp[MAX]={0};
int len=1;

void multiple(int n){
   int i,j,k,digit=n;
   int carry_multi = 0,carry_add = 0;
   int digit_tmp;
   for(i=0;i<len;i++){
      tmp[i]=factor[i];
      factor[i]=0;
   }
   for(i=0;n>0;i++){
      //carry_multi=0, carry_add=0;
      for(j=0;j<len;j++){
         digit_tmp=(n%10)*tmp[j]+carry_multi;
         carry_multi=digit_tmp/10;
         factor[i+j]+=(digit_tmp%10+carry_add);
         carry_add=factor[i+j]/10;
         factor[i+j]%=10;
      }
      while(carry_multi!=0||carry_add!=0){
         digit_tmp=carry_multi+carry_add;
         factor[len]+=digit_tmp%10;
         carry_add=digit_tmp/10;
         carry_multi/=10;
         len++;
      }
      //for(k=0;k<len;k++) printf("%d",factor[k]);
      //printf("\n");
      n/=10;
      if(n!=0) len++;//len+=2;
   }
   len++;
   while(factor[len-1]==0) len--;
   //for(i=0;i<len;i++) printf("%d",factor[len-1-i]);
   //printf(" d:%d l:%d",digit,len);
   //printf("\n");
}

int main(){
   int N,i;
   freopen("factor.in","r",stdin);
   freopen("factor.out","w",stdout);
   scanf("%d",&N);
   
   factor[0]=1;
   for(i=2;i<=N;i++) multiple(i);
   //for(i=0;factor[i]!=0;i++);
   //len = i;
   for(i=1;i<=len;i++){
      printf("%d",factor[len-i]);
      if(i%50==0) printf("\n");
   }
   printf("\n");
   return 0;
}
