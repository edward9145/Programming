#include <stdio.h>
#define LEN 100000
int n, m, i, hd, tl;
int a[10] = {0};
int lth[LEN], num[LEN], lst[LEN], app[LEN]={0}, rmd[LEN];
void print(int x);
void insert(int x, int residue, int last, int len);

int main(){
    int i;
    freopen("multiple.in", "r", stdin);
    freopen("multiple.out", "w", stdout);
    scanf("%d", &n);
    while (scanf("%d", &m)!=EOF)
       a[m]=1;
    hd=0, tl=-1;
    for(i=1;i<10;i++)
        if(a[i]!=0)
          insert(i, i % n, -1, 1);
    for(;lth[hd]<500;hd++){
        for (i=0;i<10;i++)
            if(a[i]!=0)
               insert(i, (rmd[hd] * 10 + i) % n, hd, lth[hd] + 1);
    }
    printf("0\n");
}

void print(int x){
    int i;
    char ans[500];
    for(i=0;x!=-1;x=lst[x])
       ans[i++] = num[x];
    for(i--;i>=0;i--)
       printf("%c", ans[i] + 48);
    printf("\n");
    exit(0);
}

void insert(int x, int residue, int last, int len){
    if(app[residue])
       return;
    num[++tl] = x;
    lst[tl] = last;
    if(!residue)
       print(tl);
    app[rmd[tl]=residue] = 1;
    lth[hd] = len;
}
