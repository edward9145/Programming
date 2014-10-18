#include<stdio.h>
int main()
{
    int bornIn[100000]={0};
    int i,x,exist=0;
    int m,n,p,k;
    scanf("%d%d%d%d",&m,&n,&p,&k);
    bornIn[0]=1;
    for(x=m;x<=k;x++)
        for(i=m;i<=(x<n?x:n);i++)
            bornIn[x]+=bornIn[x-i];
    for(i=k;i>k-p&&i>=0;i--)
         exist+=bornIn[i];
    printf("%d\n",exist);
    system("pause");
    return 0;
}
