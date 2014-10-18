//-------points.c
#include<stdio.h>
#include<math.h>

typedef struct
{
   int x,y;
}point;

double S(point a,point b,point c)
{
   return (b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y);
}

int main()
{
   int n,i;
   double area=0;
   point a[15];
   for(i=0;scanf("%d",&(a[i].x))!=EOF&&scanf("%d",&(a[i].y))!=EOF;i++)
   {
      if(i>=2)
         area+=fabs((a[i].y-a[0].y)*(a[i-1].x-a[0].x)-(a[i].x-a[0].x)*(a[i-1].y-a[0].y));
   }
   printf("%.2f",area*0.5);
   //while(1);
   return 0;
}
