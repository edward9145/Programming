#include<stdio.h>
#define MAX 300000
long long pos[MAX]={0};
int line;
int main(){
    int i=1;
    char c;
    FILE *fp;
    fp=fopen("invert.in","r");
    while((c=getc(fp))!=EOF)
        if(c=='\n')
            pos[i++]=ftell(fp);
    line=i;
//    for(i=0;i<line;i++) printf("%d\n",pos[i]);
    for(i=line-1;i>=0;i--){
        fseek(fp,pos[i],SEEK_SET);
        while((c=getc(fp))!='\n' && c!=EOF)
            putchar(c);
        if(i!=0) putchar('\n');
    }
    getchar();
    fclose(fp);
    return 0;
}

