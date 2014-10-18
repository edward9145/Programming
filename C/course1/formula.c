//----formula.c-----//
#include<stdio.h>
double valid(double x)
{
  long t;
  t=(x*10000000+5)/10;  /*单精度数h乘以1000后再加5，相当于对h中的第三位小数进行四舍五入,除以10后将其赋给一个长整型数时就把第三位小数后的数全部截去*/
  return (double)t/1000000;  /*除以100，保留2位小数*/
}

int main()
{
  int n,i;
  float x;
  double ex=1.0,factorial=1.0,power=1.0;
  scanf("%f %d",&x,&n);
/*  if(x==0)
  {
    printf("1.000000");
    return 0;
  }
*/
  for(i=1;i<=n;i++)
  {
      factorial*=i;
      power*=x;
      ex=ex+power/factorial;
  }
  ex=valid(ex);
  printf("%.6f",ex); 
  return 0;
}
