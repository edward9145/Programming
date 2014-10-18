#include<stdio.h>
int main()
{
    int a[100],b[100],i,j,k,l,exist;
    i=0;
    while(a[i]!=-1){
      scanf("%d",&a[i]);
      if(a[i]==-1)break;
      i++;
    }
    j=0;
    while(b[j]!=-1){
      scanf("%d",&b[j]);
      if(b[j]==-1)break;
      j++;
    }
    
    for(k=0;k<i;k++)
    {
      exist=0;
      for(l=0;l<j;l++)
      {  
        if(a[k]==b[l])
          exist=1;
      }
      if(exist==0)printf("%d ",a[k]);
    }
    return 0;    
}
