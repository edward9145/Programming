#include<stdio.h>

int main()
{
   int i,j,tmp,top=0;
   int stack[50];
   int N;
   scanf("%d",&N); 
   stack[0]=0;
   j=1;
   for(i=1;i<=N;i++){
      scanf("%d",&tmp);
      if(tmp==stack[top]) top--;
      else if(tmp==i) {j=i+1;continue;}
      else{
         while(j<tmp) stack[++top]=j++;
         j++;
      }
      //printf("top=%d\n",top);
   }
   if(top==0) printf("YES\n");
   else printf("NO\n");
   //while(1);
   return 0;
}
