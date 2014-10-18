#include<stdio.h>

int main()
{
    FILE *rf,*wf;
    int word=1;
    char ch;
    rf=fopen("fcopy.in","r");
    wf=fopen("fcopy.out","w");
    while((ch=fgetc(rf))!=EOF)
    {
      if(ch=='\t') ch=' ';
      if(ch!=' '||word==1) fprintf(wf,"%c",ch);
      if(ch==' '||ch=='\t')word=0;
      else word=1;
    }
    fclose(rf);
    fclose(wf);
    return 0;  
}
