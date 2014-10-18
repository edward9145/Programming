//------copy.c
#include<stdio.h>

int main()
{
  FILE *fp;
  int i=0,j,word=1;
  char ch,*s,*t,*r,copy;
      s=(char*)malloc(sizeof(char));
      t=s;

    fp=fopen("fcopy.in","r");
    while((ch=fgetc(fp))!=EOF)
     {i++,strcat(s,&ch);}
  //  strcat(s,'\0');
  printf("%d %d",strlen(s),i);
    r=(char*)malloc(sizeof(char));
    t=r;
    for(j=0;j<i;j++)
    {
      if((*s)==' ')
        word=0;
      else
        word=1;
      if(word==1)
      {
        copy=*s;
        strcat(r,&copy);
      }
      s++;
    }
    fclose(fp);
  //  t=s;
    fp=fopen("fcopy.out","w");
    fprintf(fp,"%s",r);
    fclose(fp);
  
  while(1);
  return 0;  
}
