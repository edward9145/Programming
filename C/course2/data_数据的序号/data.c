#include<stdio.h>
#include<stdlib.h>
#define MAX 200002
int data[MAX]={0};
int order_tmp[MAX]={0};
int order[MAX]={0};

int cmp(const void *a,const void *b){
   return *(int*)a-*(int*)b;
}

int search(int a[],int low,int high,int x){
   int mid;
   while(low<=high){
      mid=(low+high)/2;
      if(x<a[mid])
         high=mid-1;
      else if(x>a[mid])
         low=mid+1;
      else return mid;
   }
   return -1;
}

int main()
{
   int i=0,j=0,x;
   int data_len,order_len,count=1;
   char c;
   i=0;
   do{scanf("%d%c",&x,&c);
      data[i]=x;
      order_tmp[i++]=x;
   }while(c!='\n');
   data_len=i;
   qsort(order_tmp,i,sizeof(int),cmp);
   
   order[0]=order_tmp[0];
   for(i=1;i<data_len;i++)
      if(order[j]!=order_tmp[i])
         order[++j]=order_tmp[i];
   order_len=j+1;
   //for(i=0;i<order_len;i++) printf("%d ",order[i]); printf("\n");
   for(i=0;i<data_len;i++)
      printf("%d ",search(order,0,order_len-1,data[i])+1);
   printf("\n");
   
   system("pause");
   return 0;
}
