#include<stdio.h>
float shang(float data1,float data2)
{
    float x,sgn=1.0;
    int y;
    x=data1/data2;
    if(x<0)
    {
        sgn=-1.0;
        x=sgn*x;
    }
    y=(int)(x*1000);
    if(y%10>=5)
    {
        y++;
        x=y/1000.0;    
    }
    return sgn*x;
}

int main()
{
    int data1,data2;
    float result;
    char op;
    scanf("%d %d %c",&data1,&data2,&op);
    if(op=='+')printf("%d",data1+data2);
    if(op=='-')printf("%d",data1-data2);
    if(op=='*')printf("%d",data1*data2);
    if(op=='/')
    {
        result=shang((float)data1,(float)data2);
        if(result-(int)result!=0)
            printf("%.2f",result);
        else
            printf("%d",(int)result);
    }
    return 0;    
}
