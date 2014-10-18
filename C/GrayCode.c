#include<stdio.h>
#define MAX 16
/*
Reflected Gray Code
1)count 1s in current code;
2)if counts is even, change a(0);
3)else find j, and a(j)=1, and for each i that j>i a(i)=0
  change a(j+1);
*/

int Gray[MAX]={0};

int count(int a[],int l){
    int i,c=0;
    for(i=0;i<l;i++)
        if(a[i]==1)
            c++;
    return c;
}

int find(int a[],int l){
    int i;
    for(i=0;Gray[i]!=1;i++);
    return i;
}

void print(int a[],int l){
    int i;
    for(i=0;i<l;i++)
        printf("%d",a[l-1-i]);
    printf("\n");
}

int main(){
    int n,n2=1;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) n2*=2;
    //printf("%d\n",n2);
    printf("\n");
    for(i=0;i<n2;i++){
        print(Gray,n);
        if(count(Gray,n)%2==0){
            Gray[0]=1-Gray[0];
        }
        else{
            j=find(Gray,n);
            Gray[j+1]=1-Gray[j+1];
        }
    }
    system("pause");
    return 0;
}
