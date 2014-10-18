/*
test data:
1 2 6
*/

#include<stdio.h>
#define MAX 1000
int adigitSum(int[],int);
int digitSum(int);
void print(int[],int);
int multi(int[],int[],int,int);
void add(int[],int[],int);
void reset(int[],int);

int main(){
   int a,k,n;
   int i,j;
   int dSum,kdSum;
   int len,k_len,aDigit[1000]={0},kDigit[10]={0},akDigit[5000]={0};
//   freopen("sequence.in","r",stdin);
//   freopen("sequence.out","w",stdout);
   scanf("%d%d%d",&a,&k,&n);
   
   for(i=0;a!=0;i++){
      aDigit[i] = a%10;
      a /= 10;
   }
   len = i;
   for(i=0;k!=0;i++){
      kDigit[i] = k%10;
      k /= 10;
   }
   k_len = i;   
   for(i=1;i<=n;i++){
      dSum = adigitSum(aDigit,len);
      for(j=0;j<len;j++) akDigit[j]=aDigit[j];
      len = multi(akDigit,kDigit,len,k_len);
      kdSum = adigitSum(akDigit,len);
      
      if(dSum > kdSum){
         aDigit[len]=1;
      }
      else if(dSum == kdSum){

      }
      else{
         aDigit[len]=1;
      }
      len++;
      printf("%d %d\n",dSum,kdSum);
      dSum = kdSum;
   }
   
   print(aDigit,len);
      
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

int adigitSum(int digit[],int len){
   int i,sum=0;
   for(i=0;i<len;i++)
      sum += digit[i];
   return sum;
}


void print(int digit[],int len){
   int i;
   for(i=0;i<len;i++)
      printf("%d",digit[len-1-i]);
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
