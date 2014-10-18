#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}snode;

void createlist(snode *L)
{
    snode *p;
    int i=0;
    char c;
    p=L;
    do{
      p->next=(snode*)malloc(sizeof(snode));
      p=p->next;
      c=getchar();
    if(c=='\n')break;
      p->data=c-'0';
      i++;
    }while(c!='\n');
    p->next=NULL;
  //  printf("%d\n",i);
}

void delall(snode *L,int n)
{
    snode *p,*s;
  int i;
    for(i=0;i<n;i++)
    {
      s=L;
      p=s->next;
      while(p->next)
      {
        if(p->data>p->next->data)
        {
          s->next=p->next;
          break;
        }
          p=p->next;
          s=s->next;
      }
    }
}

void output(snode *L)
{
  snode *p;
  p=L->next;
  while(p->next)
  {
      printf("%d",p->data);
      p=p->next; 
  }
}

int main()
{
    snode S;
    int N;
    createlist(&S);
    scanf("%d",&N);
    delall(&S,N);
    output(&S);
    
 //   while(1);
    return 0;  
}
