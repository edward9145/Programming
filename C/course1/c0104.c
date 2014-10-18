#include<stdio.h>

int fun(float x)
{
    int b;
    b=x*10;
    if(b%10<5)
     return b/10;
    else
     return b/10+1;
}

main()
{
    float a;
    scanf("%f",&a);    
    printf("%d",fun(a));
}
