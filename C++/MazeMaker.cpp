#include<stdio.h>
#define M 11
#define N 11
int main()
{
   FILE* out;
   out=fopen("maze.in","w");
   int i,j;
   for(i=0;i<M;i++){
      for(j=0;j<N;j++)
         fprintf(out,"1 ");
      fprintf(out,"\n");
   }
}
