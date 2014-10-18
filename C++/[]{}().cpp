#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;  
}snode;

typedef struct STACK
{
    int length;
    snode *top;
}stack;

void createStack(stack *s)
{
    snode *p;
    p=NULL;
  //  p->next=NULL;
    s->top=p;
    s->length=0;
}

int push(stack *s,int e)
{
    snode *p,*q;
    p=(snode*)malloc(sizeof(snode));
 

    p->data=e;
    p->next=s->top;
    s->top=p;
    s->length++;
    return s->top->data;
}

int voidpop(stack *s,int *e)
{
    if(s->length==0)return -1;
    *e=s->top->data;
    s->top=s->top->next;
    s->length--;
}


int main()
{
    stack S;
    int i,x,a[10];
    createStack(&S);
    for(i=0;i<10;i++)
    {
      printf("%d\n",i);
      push(&S,i);
    }
    puts("\n");
    for(i=0;i<10;i++)
    {
      voidpop(&S,&a[i]);
      printf("%d\n",a[i]); 
    }  
 
     if((&S)->length==0){
        printf("%d\n",(&S)->length); }
     
 //   printf("\n%d\n",(&S)->top->data);
 //   printf("%d\n",(&S)->length);     
    char *c,ch;
    c="(){}()\0";
    puts(c);
    while(*c!='\0');
    {
      ch=*c;
      c++;
      if(ch=='(')
        push(&S,1);
      if(ch==')')
      {
        if((&S)->top->data==1)
          voidpop(&S,&x);
        else
          push(&S,2);
      }
      if((&S)->length==0)printf("valid");
      else printf("Incalid");
    }
    
    
    
   while(1);
    return 0;
}
