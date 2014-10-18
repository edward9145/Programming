//-------xor.c
#include<stdio.h>

int main()
{
   int a[40],i=0,j,m,end,tmp,out;
   char ch;
   end=2;
   while(1){
      scanf("%d%c",&a[i++],&ch);
      if(ch=='\n')end--;
      if(end==0)break;
   }
   m=i;
   for(i=m-1;i>0;i--){
      for(j=i;j<m;j++){
         if(a[j-1]>a[j])
         {tmp=a[j-1];a[j-1]=a[j];a[j]=tmp;}
      }
   }
     
      for(i=m-1;i>=0;i--)
      {
         out=1;
         for(j=i-1;j>=0;j--)
         {
            if(a[i]==a[j]){i=j;out=0;break;}   
         }
         if(out==1)printf("%d ",a[i]);
      }
//   while(1);
   return 0;   
}
