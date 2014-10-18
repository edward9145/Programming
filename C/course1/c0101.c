//计算平均值
#include<stdio.h>

main()
{
    int x,y,z,sum;
    float avg;
    scanf("%d %d %d",&x,&y,&z);
    sum=x+y+z;
    avg=(x+y+z)/3.0;
    printf("%d\n%.2f",sum,avg);
}
