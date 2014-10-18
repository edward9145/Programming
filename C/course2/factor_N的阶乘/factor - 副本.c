#include<stdio.h>
#define MAX 1000
int factor[MAX]={0};
int len_f=1;

int multi(int a[],int b[],int len_a,int len_b);
void add(int a[],int b[],int len);
void reset(int c[],int len);
int main(){
   int N,i,n,j;
   int num[MAX],len_num;
   freopen("factor.in","r",stdin);
   freopen("factor.out","w",stdout);
   scanf("%d",&N);
   factor[0]=1;
   for(i=2;i<=N;i++){
      n=i;
      for(j=0;n>0;j++){
         num[j]=n%10;
         n/=10;
      }
      len_num=j;
      //int k;
      //for(k=1;k<=len_f;k++) printf("%d",factor[len_f-k]); printf(" ");
      //for(k=1;k<=len_num;k++) printf("%d",num[len_num-k]); printf("\n");
      len_f = multi(factor,num,len_f,len_num);
   }
   
   for(i=1;i<=len_f;i++){
      printf("%d",factor[len_f-i]);
      if(i%50==0) printf("\n");
   }
   //system("pause");
   return 0;
}

int multi(int a[],int b[],int len_a,int len_b){
   int i,j;
   int digit,carry_multi=0;
   int c[MAX]={0},len_c;
   int tmp_c[MAX]={0};
   len_c = len_a+len_b;
   for(i=0;i<len_b;i++){
      reset(tmp_c,len_c);
      for(j=0;j<=len_a;j++){
         digit=a[j]*b[i]+carry_multi;
         tmp_c[i+j]=digit%10;
         carry_multi=digit/10;
      }
      add(c,tmp_c,len_c);
   }
   if(c[len_c-1]==0)
      len_c--;
   for(i=0;i<len_c;i++)
      a[i]=c[i];
   return len_c;
}

void add(int a[],int b[],int len){
   int i,digit,carry_add=0;
   int c[MAX]={0};
   for(i=0;i<=len;i++){
      digit=a[i]+b[i]+carry_add;
      c[i]=digit%10;
      carry_add=digit/10;
   }
   for(i=0;i<len;i++)
      a[i]=c[i];
}

void reset(int c[],int len){
   int i;
   for(i=0;i<=len;i++) c[i]=0;
}
