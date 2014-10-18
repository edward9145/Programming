#include<stdio.h>
int main()
{
    int n,a[100],max,min,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);    
        if(i==0)
        {
            max=a[0];
            min=a[0];
        }
        if(a[i]>max)
            max=a[i];    
        if(a[i]<min)
            min=a[i];
    }
    printf("%d %d",max,min);
    return 0;    
}
