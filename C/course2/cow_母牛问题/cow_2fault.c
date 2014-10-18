#include<stdio.h>

int main()
{
    int bornIn[50000]={0};
    int deadIn[50000]={0};
    int existIn[50000]={0};
    int m,n,p,k;
    int i,x;
    scanf("%d%d%d%d",&m,&n,&p,&k);
    
    bornIn[0]=1;
    existIn[0]=1;
    
    for(x=1;x<=k;x++){
        if(x<m){
            bornIn[x]=0;
        }
        else if(x<n){
            bornIn[x]=1;
        }
        else{
            for(i=m;i<=n;i++)
                bornIn[x]+=bornIn[x-i];
        }
        
        if(x>=p) deadIn[x]=bornIn[x-p];
        
        existIn[x]=existIn[x-1]+bornIn[x]-deadIn[x];
    }
    
    printf("%d\n",existIn[k]);
    
    system("pause");
}
