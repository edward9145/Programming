//----formula.c-----//
#include<stdio.h>
double valid(double x)
{
  long t;
  t=(x*10000000+5)/10;  /*��������h����1000���ټ�5���൱�ڶ�h�еĵ���λС��������������,����10���丳��һ����������ʱ�Ͱѵ���λС�������ȫ����ȥ*/
  return (double)t/1000000;  /*����100������2λС��*/
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
