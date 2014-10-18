#include<stdio.h>
int c[20],num,bigger;

void add(int a[],int b[],int i,int j)
{
    int carry,max,n,n1;     //carry：进位；n:计数器;n1:a[],b[]的对应相加位； 
    if(i>=j)max=i;
    else max=j;
    max++;
    printf("\nmax=%d\n",max);
    
    carry=0;
    for(n=19;n>=20-max;n--)
    {
     n1=n-10;
     if(a[n1]+b[n1]+carry>=10)
     {
      c[n]=(a[n1]+b[n1]+carry)%10;
      carry=1;      
     }
     else
     {
      c[n]=a[n1]+b[n1]+carry;
      carry=0;      
     }
    }

    if(c[n+1]!=0)
     num=max;
    else
     num=max-1;
    printf("num=%d\n",num);
}

void minus(int a[],int b[],int i,int j)
{
    int take,max,n,n1;                  //take:退位； 
    if(i>=j)max=i;
    else max=j;
    max++;
    printf("\max=%d\n",max);
    
    take=0;
    for(n=19;n>=20-max;n--)
    {
     n1=n-10;
     if(a[n1]-take-b[n1]<0)
     {
      c[n]=a[n1]-take-b[n1]+10;
      take=1;      
     }
     else
     {
      c[n]=a[n1]-take-b[n1];
      take=0;      
     }
    }
    if(take==1)
     minus(b,a,i,j);
    
    if(c[n]!=0)
     num=max;
    else
     num=max-1;
    printf("num=%d\n",num);
}

void multi(int a[],int b[],int i,int j)
{
    
}

main()
{
for(int i=0;i<20;i++)c[i]=0;

    int a[10],b[10],i,j,n;          //i:a的位数；j:b的位数；n: 计数器； 
    char ch[10];
    
    for(i=0;i<10;i++)
    {
     scanf("%c",&ch[i]);
     if(ch[i]==10)break;
    }
    for(n=0;n<10;n++)
     a[n]=0;
    for(n=10-i;n<10;n++)
     a[n]=ch[n-(10-i)]-48;
    
    for(j=0;j<10;j++)
    {
     scanf("%c",&ch[j]);
     if(ch[j]==10)break;  
    }
    for(n=0;n<10;n++)
     b[n]=0;
    for(n=10-j;n<10;n++)
     b[n]=ch[n-(10-j)]-48;
    
    printf("i=%d\na=",i);
    for(n=10-i;n<10;n++)
     printf("%d",a[n]);
    printf("\n");
    printf("j=%d\nb=",j);
    for(n=10-j;n<10;n++)
     printf("%d",b[n]);
    printf("\n");
    
add(a,b,i,j);
    printf("a+b=");
    for(n=20-num;n<20;n++)
     printf("%d",c[n]);
    printf("\n\n");

minus(a,b,i,j);
    printf("|b-a|=");
    for(n=20-num;n<20;n++)
     printf("%d",c[n]);
    printf("\n\n");

multi(a,b,i,j);
    printf("a*b=");
    for(n=20-num;n<20;n++)
     printf("%d",c[n]);

    getchar();
}
