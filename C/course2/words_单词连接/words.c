/*
find Euler's path

test data:
mouse
acm
malform

*/
#include<stdio.h>

int main(){
   char M[2000];
   int i,j,k;
   int head,tail;
   int Graph[26][26]={0};
   int root,pair,father[26]={0},exist[26]={0};
   int od[26]={0},id[26]={0};
   int even=0,odd=0;
   while(scanf("%s",M)!=EOF){
      head = M[0]-'a';
      tail = M[strlen(M)-1]-'a';
      Graph[head][tail] += 1;
      exist[head]=1;
      exist[tail]=1;
   }
   for(i=0;i<26;i++)
      if(exist[i])
         father[i]=i+1;
      
   for(i=0;i<26;i++)
      for(j=0;j<26;j++)
         if(Graph[i][j]>0){
            root=father[j];
            for(k=0;k<26;k++)
               if(father[k]==root)
                  father[k]=father[i];
         }
         
   int sameroot;
   for(i=0;father[i]==0;i++);
   sameroot=father[i];
   for(i=0;i<26;i++)
      if(father[i]!=0 && father[i]!=sameroot){
         printf("no\n");
         return 0;
      }
   
//   for(i=0;i<26;i++) printf("%d ",father[i]); printf("\n");

   for(i=0;i<26;i++){
      for(j=0;j<26;j++){
         od[i]+=Graph[i][j];
         id[j]+=Graph[i][j];
      }
   }
   
   //printDegree(exist,od,id);

 int first=0,last=0;
   for(i=0;i<26;i++){
      if(od[i]||id[i]){
         if(id[i]==od[i]) even++;
         else if((od[i]+1==id[i]) && first==0) first++;
         else if((od[i]==id[i]+1) && last==0) last++;
         else{
            printf("no\n");
            system("pause");
            return 0;
         }
      }
   }
  // printf("first: %d\nlast:  %d\n",first,last);
   if(first && last)
      printf("yes\n");
   else if(even && !first && !last)
      printf("yes\n");
   else
      printf("no\n");
   
   system("pause");
   return 0;
}

