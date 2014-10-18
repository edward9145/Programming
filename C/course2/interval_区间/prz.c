#include<stdio.h>
typedef struct{
   int a;
   int b;
}Interval;
Interval I[60000];

void qsort(Interval I[],int low,int high)
{
   int i,j;
   Interval swap=I[low];
   i=low;
   j=high;
   while(i<j){
      while(i<j&&I[j].a>swap.a) j--;
      if(i<j){ I[i]=I[j]; i++;}
      while(i<j&&swap.a>I[i].a) i++;
      if(i<j){ I[j]=I[i]; j--;}
   }
   I[i]=swap;
   if(low<i) qsort(I,low,i-1);
   if(j<high) qsort(I,j+1,high);
}

int main(){
   freopen("prz.in","r",stdin);
   freopen("prz.out","w",stdout);
   int n;
   int i,j;
   scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%d %d",&(I[i].a),&(I[i].b));
   
   qsort(I,0,n-1);
   
   //for(i=0;i<n;i++) printf("%d %d\n",I[i].a,I[i].b);
   int cur,pre;
   cur=I[0].a;
   pre=I[0].b;
   for(i=1;i<n;i++){
      if(I[i].a>pre){
         printf("%d %d\n",cur,pre);
         cur=I[i].a;
         pre=I[i].b;
      }
      if(I[i].b>pre)
         pre=I[i].b;
   }
   printf("%d %d\n",cur,pre);
//   while(1);
   return 0;
}
