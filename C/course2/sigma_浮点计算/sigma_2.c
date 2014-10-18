#include<stdio.h>
#define DECIMAL 50
#define INTEGER 20
int main(){
   int k,x,m,n;
   long long integer=0;
   char decimal[DECIMAL]={0};
   freopen("sigma.in","r",stdin);
   scanf("%d%d%d%d",&k,&x,&m,&n);
   int i,j;
   double sum=0.0;
   for(i=-m;i<0;i++){
      double power=(double)k*1E13;
      for(j=i;j<0;j++) power/=(double)x; 
      sum+=power;
   }
   sprintf(decimal,"%.1lf",sum);
//printf("%s\n",decimal);
   int swap,len=strlen(decimal);
   if(len>15) integer+=decimal[0]-'0';
   
   for(i=0;i<len/2;i++){
      swap=decimal[i];
      decimal[i]=decimal[len-1-i];
      decimal[len-1-i]=swap;
   }
//printf("%s\n",decimal);
//sscanf(decimal,"%15s",decimal_tmp);
//printf("%s\n",decimal_tmp);
  
   for(i=0;i<=n;i++){
      long long power=k;
      for(j=1;j<=i;j++) power*=x;
      integer+=power;
   }
   
   printf("%d.",integer);
   for(i=0;i<15;i++)
      if(decimal[14-i]!='.')
         printf("%c",decimal[14-i]);
//printf("\n%s",decimal);
   printf("\n");
while(1);
   return 0;
}
