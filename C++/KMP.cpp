/*
* KMP (Knuth-Morris-Pratt)
* Author: Edward.Wu
* Ref: Introduction of Algorithms
* 2011/8/17 1:24 BUAA
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>

#define TMAX 1000
#define PMAX 100
/*test string
ababaca
bacbabababacababaca
*/
char P[PMAX];
char T[TMAX];

void o(char *str){
    printf("%s",str);
}

int* computePrefix(char *P){
    int m = strlen(P);
    int *pi=(int*)malloc(sizeof(int)*m);
    
    int k=-1;
    int q;
	pi[0]=-1;
    for(q=1;q<m;q++){
        while(k>=0 && P[k+1]!=P[q])
            k = pi[k];
        if(P[k+1]==P[q])
            k = k+1;
        pi[q]=k;
    }
    return pi;
}

void KMP_matcher(char *T,char *P){
    int n = strlen(T);
    int m = strlen(P);
    int* pi = computePrefix(P);
    int i;
	int q=-1;   //revise index

    //for(i=0;i<m;i++) pi[i]--; //revise index
    
    
    for(i=0;i<n;i++){
        while(q>=0 && P[q+1]!=T[i])
            q = pi[q];
        if(P[q+1]==T[i])
            q = q+1;
        if(q==m-1){
            printf("Pattern occurs with shift: %d\n",i-m+1);
            //show the position of the pattern string
            int j;
            for(j=0;j<i-m+1;j++)o(" ");
            for(j=0;j<m;j++)o("_");
            printf("\n%s\n",T);
            for(j=0;j<i-m+1;j++)o(" ");
            printf("^ %d\n",i-m+1);
            //look for the next match
            q = pi[q];
        }
    }
}

void showArray(int *pi,int m)
{
    int i;
    o("\ni  ");
    for(i=0;i<m;i++)
        printf("%d ",i%10);
    o("\nP  ");
    for(i=0;i<m;i++)
        printf("%c ",P[i]);
    o("\npi ");
    for(i=0;i<m;i++)
        printf("%d ",pi[i]+1);	//revise pi
    o("\n\n");
}

int main(){
    o("input pattern P:\n");
    scanf("%s",P);
    int *pi = computePrefix(P);
    showArray(pi,strlen(P));
    
    o("input text T:\n");
    scanf("%s",T);
    o("\n");
    KMP_matcher(T,P);
    
    o("\n");
    system("pause");
    return 0;
}
