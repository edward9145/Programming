#include<stdio.h>
typedef struct ascii
{
   int num;
   int weight;
}ASC;
typedef struct sort
{
   char ch;
   int num;
   int weight;
}SORT;
int cmp(SORT a,SORT b)
{
   if(a.num<b.num)return -1;
   if(a.num>b.num)return 1;
   if(a.num==b.num)
      if(a.weight>b.weight)return -1;
      else return 1;   
}
void swap(SORT *x,SORT *y)
{
   SORT tmp;
   tmp=*x; *x=*y; *y=tmp;   
}

int main()
{
   ASC asc[256]={0,0};
   SORT list[256];
   int i,j,len,w,max;
   char c;
   w=0;
   while((c=getchar())!='\n'||(c==EOF))
   {
      asc[(int)c].num++;
      w++;
      if(asc[(int)c].weight==0)asc[(int)c].weight=w;
   }

   j=0;
   for(i=0;i<256;i++)
   {
      if(asc[i].num!=0)
      {
         list[j].ch=(char)i;
         list[j].num=asc[i].num;
         list[j].weight=asc[i].weight;
         j++;
      } 
   }
   len=j;
   for(i=0;i<len;i++)
      for(j=len-1;j>i;j--)
         if(cmp(list[j-1],list[j])<0)
            swap(&list[j-1],&list[j]);
   
   for(i=0;i<len;i++)
   {
      j=0;
      while(j<4)
      {
         printf("%c-%d",list[i].ch,list[i].num,list[i].weight);
         j++;
         if(j==4)break;
         putchar(' ');
         i++;
         if(i==len)break;
      }
      putchar('\n');
   }
   
//   while(1);
}
