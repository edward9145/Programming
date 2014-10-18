#include<stdio.h>
#define M 11
#define N 11
#define MN 120
int maze[M][N];
int move[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
char direction[4]={'W','S','E','N'};
int stack[MN][3];

int main()
{
   FILE *in;
   in=fopen("Maze.in","r");
   int i,j,k,g,h,l;
   int NoWay=1;
   for(i=0;i<M;i++)
      for(j=0;j<N;j++)
         fscanf(in,"%d",&maze[i][j]);
   for(i=0;i<M;i++){
      for(j=0;j<N;j++)
         printf("%d",maze[i][j]);
      printf("\n");
   }
   int top=0;
   stack[top][0]=1;
   stack[top][1]=1;
   stack[top][2]=-1;
   while(top>=0){
      i=stack[top][0];
      j=stack[top][1];
      k=stack[top][2];
      top--;
      //printf("%d:%d,%d,%d\n",top,stack[top][0],stack[top][1],stack[top][2]);
      while(k<4){
         g=i+move[k][0];
         h=j+move[k][1];
         
         if(maze[g][h]==0){
            maze[g][h]=2;
            top++;
            stack[top][0]=g;
            stack[top][1]=h;
            stack[top][2]=k;
            if(g==M-2 && h==N-2){
               printf("Find a way!\n");
               NoWay=0;
               break;
            }
            i=g;
            j=h;
            k=-1;
         }
         k++;
      }
      if(NoWay==0)break;
      
   }
   if(NoWay)printf("No Way!");
   else{
         for(l=0;l<=top;l++){
            printf("%d,%d,%c\n",stack[l][0],stack[l][1],direction[stack[l][2]]);
         }
      for(i=0;i<M;i++){
         for(j=0;j<N;j++)
            printf("%d",maze[i][j]);
         printf("\n");
      }
   }
   while(1);
}
