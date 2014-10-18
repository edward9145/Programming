#include<stdio.h>
#define MAX 60
int G[MAX][MAX]={0};
int father[MAX]={0};

void print(int len){
   int i,j;
   printf("   ");
   for(i=1;i<len;i++) printf("%2d",i);
   printf("\n");
   for(i=1;i<len;i++){
      printf("%2d- ",i);
      for(j=1;j<len;j++){
         printf("%d ",G[i][j]);
      }
      printf("\n");
   }
}

int main(){
   int m,n;
   freopen("collect.in","r",stdin);
   freopen("collect.out","w",stdout);
   scanf("%d%d",&n,&m);
   
   int i,j;
   int tmp;
   for(i=1;i<=n;i++)
      for(;scanf("%d",&tmp)&&tmp!=0;G[i][tmp]=1);
   for(;i<=n+m;i++)
      for(;scanf("%d",&tmp)&&tmp!=0;G[i][tmp]=1);
      
   int len=i;
//   print(len);
   for(i=1;i<len;i++) father[i]=i;
   for(i=1;i<len;i++){
      for(j=1;j<len;j++){
         if(G[i][j]!=0)
            if(father[i]<father[j])
               father[j]=father[i];
      }
   }
//   for(i=1;i<len;i++) printf("%d ",father[i]);  printf("\n");
   int noTrash = 1;
   for(i=1;i<len;i++)
      if(father[i]>n){
         noTrash = 0;
         printf("%d ",i);
      }
   if(noTrash) printf("-1");
   fclose(stdin);
//   while(1);
//   system("pause");
   return 0;
}
