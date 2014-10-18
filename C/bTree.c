#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define MaxLeaf 50
typedef char DATATYPE;
typedef struct node{
   DATATYPE data;
   struct node *lchild,*rchild;
   struct node *parent;
}BTnode,*BTree;

BTree ROOT,LEAF[MaxLeaf];
int LeafNum=0;

BTree createTree(){
   BTree stack[MaxSize],p,T=NULL;
   char c;
   int flag,top=-1;
   while(1){
      c=getchar();
      switch(c){
         case '(':stack[++top]=p;
                  flag=1;
            break;
         case ')':top--;
                  if(top==-1) return(T);
            break;
         case ',':flag=2;
            break;
         default: p=(BTree)malloc(sizeof(BTnode));
                  p->data=c;
                  p->lchild=NULL;
                  p->rchild=NULL;
                  p->parent=NULL;
                  if(T==NULL){
                     T=p;
                     ROOT=p;
                  }
                  else if(flag==1){
                     p->parent=stack[top];
                     stack[top]->lchild=p;
                  }
                  else{
                     p->parent=stack[top];
                     stack[top]->rchild=p;
                  }            
            break;
      }
   }
}

void visit(BTree node){
   if(node->lchild==NULL&&node->rchild==NULL){
      printf("%c ",node->data);
      LEAF[LeafNum++]=node;
   }
}

void preOrder(BTree T){
   if(T!=NULL){
      visit(T);
      preOrder(T->lchild);
      preOrder(T->rchild);
   }
}

int findPath(BTree T){
   if(T!=NULL){
      printf("%c ",T->data);
      return findPath(T->parent)+1;
   }
   else return 0;
}

void swap(BTree *a,BTree *b){
   BTree tmp;
   tmp=*a; *a=*b; *b=tmp;
}
int main(){
   BTree T;
   int i,j,tmp,maxpos,maxlen=0;
   
   T=createTree();
   printf("b的叶子结点:");
   preOrder(T);
   
   for(i=0;i<LeafNum;i++)
      for(j=LeafNum-1;j>i;j--)
         if(LEAF[j]->data < LEAF[j-1]->data)
            swap(&LEAF[j],&LEAF[j-1]);   
   
   printf("\nALLPATH:");
   for(i=0;i<LeafNum;i++){
      printf("\n%c到根结点的路径:",LEAF[i]->data);
      tmp=findPath(LEAF[i]);
      if(tmp>maxlen){
         maxpos=i;
         maxlen=tmp;
      }
   }

   printf("\n\n第一条最长路径长度:%d",maxlen);
   printf("\n第一条最长路径:");
   findPath(LEAF[j]);
   while(1);
   return 0;
}
