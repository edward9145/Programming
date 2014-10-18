//-----students.c
#include<stdio.h>
typedef struct student
{
   int id;
   char name[50];
   int age;
}STU;
void swapstu(STU *x,STU *y)
{
   STU tmp;
   tmp=*x;*x=*y;*y=tmp;   
}
int main()
{
   STU stu[50],tmp;
   int n,i,j;
   scanf("%d",&n);
   for(i=0;i<n;i++)
      scanf("%d %s %d",&(stu[i].id),stu[i].name,&(stu[i].age));
   
   for(i=0;i<n;i++)
      for(j=n-1;j>i;j--)
         if(strcmp(stu[j-1].name,stu[j].name)>0)
            swapstu(&stu[j-1],&stu[j]);
         //{tmp=stu[j-1];stu[j-1]=stu[j];stu[j]=tmp;}
   for(i=0;i<n;i++)
      printf("%3d%6s%3d\n",(stu[i].id),stu[i].name,(stu[i].age));
   putchar('\n');
   for(i=0;i<n;i++)
      for(j=n-1;j>i;j--)
         if(stu[j-1].age>stu[j].age)
            swapstu(&stu[j-1],&stu[j]);
   for(i=0;i<n;i++)
      printf("%3d%6s%3d\n",(stu[i].id),stu[i].name,(stu[i].age));
      
   while(1);
   return 0;
}
