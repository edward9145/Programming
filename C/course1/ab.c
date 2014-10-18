#include<stdio.h>
int main()
{
    int a,b,n;
    int temp;
    scanf("%d",&n);
    for(a=0;a<=9;a++)
    {
        for(b=9;b>=a;b--)    
        {
            temp=(a*10+b)*(b*10+a);
            if(n==temp)
            {
                printf("%d%d",a,b);
                break;
            }
        }
    }
    if(a==b)
        printf("No Answer");
    return 0;    
}
