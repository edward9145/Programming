#include<stdio.h>
int square[2002][2002]={0};
int M,N;
void print(){
   int i,j;
    for(i=0;i<=N+1;i++){
      for(j=0;j<=M+1;j++)
         printf("%d ",square[i][j]);
      printf("\n");
   }
}

int min(int a,int b,int c){
   if(a>b) return b<c?b:c;
   else return a<c?a:c;
}

int main(){
   int len,total=0;
   int i,j;
   char str[2002];
   freopen("squares.in","r",stdin);
   freopen("squares.out","w",stdout);
   scanf("%d\n",&len);
   for(i=1;gets(str)!=NULL;i++)
      for(j=1;j<=strlen(str);j++)
         square[i][j]=str[j-1]-'0';
   N=i-1;
   M=j-1;
  //print();
   for(i=1;i<=N;i++)
      for(j=0;j<=M;j++)
         if(square[i][j]==1)
            if(square[i-1][j-1] && square[i][j-1] && square[i-1][j])
               square[i][j] = min(square[i-1][j-1],
                  square[i][j-1],square[i-1][j]) + 1;

   for(i=1;i<=N;i++)
      for(j=0;j<=M;j++)
         if(square[i][j]>=len)
            total++;
   printf("%d\n",total);
   return 0;
}
