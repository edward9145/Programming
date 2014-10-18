#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
typedef struct node snode;

snode *createlist()
{
   snode *head,*p;
   int i,n;
   head=(snode*)malloc(sizeof(snode));
   head->next=(snode*)malloc(sizeof(snode));
   p=head->next;
   do
   {
      p->next=(snode*)malloc(sizeof(snode));
      scanf("%d",&n);
      if(n==-1)break;
      p->data=n;
      p=p->next;
   }while(n!=-1);
   p->next=NULL;
   return head;
}

snode *dellist(snode *L,int del)
{
   snode *p,*s;
   s=L;
   while(s->next)
   {
      p=s->next;
      if(p->data==del)
         s->next=p->next;
      p=p->next;
      s=s->next;
   }
   return L;
}

void output(snode *L,int del)
{
  snode *p;
  p=L->next;
  while(p->next)
  {
      if(p->data!=del)
         printf("%d ",p->data);
      p=p->next; 
  }
}

int main()
{
   int del;
   snode *l;
   l=createlist();
   scanf("%d",&del);
   //l=dellist(l,del);
   output(l,del);
 // while(1);
   return 0;   
}
