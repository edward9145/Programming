#include<stdio.h>
#define MAX 400000
int Interval[MAX]={0};
int data[MAX]={0};

int main()
{
   int i,data_len;
   int x,count=1;
   char c;
   for(i=0;i<MAX;i++){
      Interval[MAX]=0;
      data[MAX]=0;
   }
   i=0;
   do{
      scanf("%d%c",&x,&c);
      Interval[x]=1;
      data[i]=x;
      i++;
   }while(c!='\n');
   data_len=i;

   for(i=0;i<MAX;i++){
      if(Interval[i]==1)
         Interval[i]=count++;
   }
   
   for(i=0;i<data_len;i++){
      printf("%d ",Interval[data[i]]);
      //if(i<data_len-1) printf(" ");
      //else
   }
   printf("\n");
   //system("pause");
   return 0;
}
