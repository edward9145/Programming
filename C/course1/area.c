#include<stdio.h>
int main()
{
    int Ax1,Ay1,Ax2,Ay2,Bx1,By1,Bx2,By2;
    int area=0,i,j,t;
    int xoy[1001][1001];
    scanf("%d %d %d %d",&Ax1,&Ay1,&Ax2,&Ay2);
    scanf("%d %d %d %d",&Bx1,&By1,&Bx2,&By2);
    if(Ay1>Ay2)
        t=Ay1;Ay1=Ay2;Ay2=t;
    if(By1>By2)
        t=By1;By1=By2;By2=t;  

    for(i=0;i<=1000;i++)
        for(j=0;j<=1000;j++)
            xoy[i][j]=0;
    
    for(i=Ax1;i<=Ax2;i++)
        for(j=Ay1;j<=Ay2;j++)
            xoy[i][j]=1;
    for(i=Bx1;i<=Bx2;i++)
        for(j=By1;j<=By2;j++)
            xoy[i][j]+=1;
    
    for(i=0;i<=1000;i++)
        for(j=0;j<=1000;j++)
            if(xoy[i][j]==2&&xoy[i][j+1]==2&&xoy[i+1][j]==2&&xoy[i+1][j+1]==2)
             area++;
    printf("%d",area);
    return 0;
}
