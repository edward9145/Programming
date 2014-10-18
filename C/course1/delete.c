//-delete.c
#include<stdio.h>
/*
void nextmin(int a[][2],int l)
{
    int j,min=0;
    for(j=0;j<l;j++)
    {
        if(a[j][0]<a[min][0]&&a[j][1]==0)
        {
          min=j;
        }
    }
    a[min][1]=1;
}
*/
int main()
{
    int s[241],_s[241],b[241],i,j,k,n,min,minnum,l;
    char c;
    i=0;
    do
    {
      c=getchar();
      if(c=='\n')break;
      s[i]=c-'0';
      _s[i]=s[i];
      b[i]=0;
      i++;
    }while(c!='\n');
    scanf("%d",&n);
  
  l=i;
    for(i=0;i<l-n;i++)
    {
      min=9;
      for(j=0;j<l;j++)
      {
        if(_s[j]<=min)
        {
          min=_s[j];
          minnum=j;  
        }  
      }
      _s[minnum]=10;
      b[minnum]=1;
    }

  for(i=0;i<l-n;i++)
  {
    if(b[i]==1)
      printf("%d",s[i]);  
  }
    while(1);
    return 0;  
}
