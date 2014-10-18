#include<stdio.h>

int main()
{
    int n,m,i;
    float s,h;
    scanf("%d %d",&n,&m);
    s=(float)n;
    h=(float)n;
    for(i=1;i<m;i++)
    {
        h*=0.25;
        s+=(h*2);
    }
    h*=0.25;
    printf("%.2f\n%.2f",s,h);
    return 0;    
}
