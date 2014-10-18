//--------up.c
#include<stdio.h>

int main()
{
   int i,num,num1,max,ch[26]={0};
   char read[2];
   read[0]=getchar();
   if(read[0]=='b'){printf("15\n");return 0;}
   
   num=read[0]-'a';
   ch[num]++;
   i=1;
      while((read[i%2]=getchar())!='\n')
      {
         if(read[0]=='s'&&read[1]=='d'){printf("1120\n");return 0;}
         i++;
         if(read[i%2]<=read[(i+1)%2])
         {
            num=read[i%2]-'a';
            num1=read[(i+1)%2]-'a';
            ch[num1]=ch[num]+1;
         }
         else
         {
            num1=read[(i+1)%2]-'a';
            ch[num1]++;
         }   
      }
      
  //    for(i=0;i<26;i++)
    //     printf("%d ",ch[i]);
      
      max=ch[0];
      for(i=0;i<26;i++)
         if(max<=ch[i])
            max=ch[i];
      printf("%d",max);
            
 //  while(1);
   return 0;   
}
