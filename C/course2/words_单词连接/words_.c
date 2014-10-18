/*
find Euler's path

test data:
mouse
acm
malform

*/
#include<stdio.h>
void printGraph(int Graph[26][26]){
   int i,j;
   printf("  ");
   for(i=0;i<26;i++)
      printf("%c ",i+'a');
   printf("\n");
   for(i=0;i<26;i++){
      printf("%c ",i+'a');
      for(j=0;j<26;j++)
         printf(Graph[i][j]?"%d ":"  ",Graph[i][j]);
      printf("\n");
   }
}
void printDegree(int exist[],int od[],int id[]){
   int i;
   printf("exist\n");
   for(i=0;i<26;i++)
      if(exist[i])
         printf("%c ",i+'a');
   printf("\n  o i\n");
   for(i=0;i<26;i++)
      printf((od[i]||id[i])?"%c %d %d\n":"",i+'a',od[i],id[i]);
}
void printArray(int a[]){
   int i;
   for(i=0;i<26;i++) printf("%c ",i+'a');
   printf("\n");
   for(i=0;i<26;i++) printf("%d ",a[i]);
   printf("\n");
}

void evaluate(int a[26][26],int b[26][26]){
   int i,j;
   for(i=0;i<26;i++)
      for(j=0;j<26;j++)
         a[i][j]=b[i][j];
}

void power(int B[26][26],int n){
   int i,j,k;
   int B_tmp[26][26]={0};
   evaluate(B_tmp,B);
   for(;n>1;n--){
      int tmp[26][26]={0};
      for(i=0;i<26;i++){
         for(j=0;j<26;j++)
            for(k=0;k<26;k++)
               tmp[i][j]+=B_tmp[i][k]*B[k][j];
      }
      evaluate(B,tmp);
   }
   
}
void reachable(int R[26][26],int I[26][26],int M[26][26],int n){
   int IM[26][26]={0};
   int i,j;
   for(i=0;i<26;i++)
      for(j=0;j<26;j++)
         IM[i][j]=I[i][j]+M[i][j];
   
   power(IM,n-1);
   
   for(i=0;i<26;i++)
      for(j=0;j<26;j++)
         R[i][j]=(IM[i][j]>0)?1:0;
}

int main(){
   char M[2000];
   int i,j,n=0;
   int head,tail;
   int Graph[26][26]={0},
       I[26][26]={0},R[26][26]={0};
   int pair,exist[26]={0};
   int od[26]={0},id[26]={0};
   int even=0,odd=0;
   while(scanf("%s",M)!=EOF){
      head = M[0]-'a';
      tail = M[strlen(M)-1]-'a';
      Graph[head][tail] = 1;
      I[head][head]=1;
      I[tail][tail]=1;
      exist[head]=1;
      exist[tail]=1;
   }
   //printGraph(Graph);
   for(i=0;i<26;i++)
      if(exist[i])
         n++;
   //printf("%d \n",n);
   reachable(R,I,Graph,n);
   //printArray(exist);
   //printGraph(R);
   int iMax=0,max=0;
   for(i=0;i<26;i++){
      int tmp=0;
      for(j=0;j<26;j++)
         tmp+=R[i][j];
      if(max<tmp){
         iMax=i;
         max=tmp;
      }
   }
   //printf("%d ",iMax);
   pair=1;
   for(j=0;j<26;j++){
      if(R[iMax][j]!=exist[j]){
         pair=0;
         break;
      }
   }
   
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
            //system("pause");
            return 0;
         }
      }
   }
  // printf("first: %d\nlast:  %d\n",first,last);
   if(first && last){
      printf("yes\n");
   }
   else if(even && !first && !last){
      if(pair) printf("yes\n");
      
      else printf("no\n");
   }
   else{
      printf("no\n");
   }
   
   //system("pause");
   return 0;
}

