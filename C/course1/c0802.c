#include<stdio.h>
//()--01  []--34  {}--67;
int main()
{
    FILE *fp;
    char ch;
    int a[81],stack[81],i,j,top;
    fp=fopen("correct.in","r");
    i=0;
    do
    {
      ch=fgetc(fp);
      if(ch=='('){a[i++]=0;}
      if(ch==')'){a[i++]=1;}
      if(ch=='['){a[i++]=3;}
      if(ch==']'){a[i++]=4;}
      if(ch=='{'){a[i++]=6;}
      if(ch=='}'){a[i++]=7;}          
    }while(ch!=EOF);
    fclose(fp);
    fp=fopen("correct.out","w");
    top=0;
    for(j=0;j<i;j++)
    {
     // fprintf(fp,"%d",a[j]);
      stack[top]=a[j];
      if(top>0)
      {
        if(stack[top]-1==stack[top-1])
        top-=2;
      }
      top++;
    }
    if(top==0)fprintf(fp,"True\n");
    else fprintf(fp,"False\n");
    fclose(fp);
    return 0;
}
