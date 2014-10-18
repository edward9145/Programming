#include<stdio.h>

main()
{
    int i=0,j=0;
    char c;
    while((c=getchar())!=EOF)
    {
     if(c==' ')i++;
     if(c=='\n')j++;
    }
    printf("%d %d",i,j);
} 
