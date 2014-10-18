#include<stdio.h>
#define MAXLEN 50
#define MAXCOUNT 600
typedef struct{
   char word[MAXLEN];
   int lineNum;
}REF;
REF ref[MAXCOUNT];
char buf[20000];

int saveWord(char *t,int num,int l){
   if(strcmp(t,"a")==0  //||strcmp(t,"A")==0 
    ||strcmp(t,"an")==0 //||strcmp(t,"An")==0 
    ||strcmp(t,"the")==0//||strcmp(t,"The")==0 
    ||strcmp(t,"and")==0)//||strcmp(t,"And")==0 )
      return 0;
   else if((*t>='a' && *t<='z')||(*t>='A' && *t<='Z')||*t=='-'){
      if(t[strlen(t)-1]=='.' || t[strlen(t)-1]==',')
         t[strlen(t)-1]='\0';
      int i;
      int len = strlen(t);
      for(i=1;i<len;i++)
         if((t[i]>='a' && t[i]<='z')||(t[i]>='A' && t[i]<='Z')||t[i]=='-') continue;
         else return 0;

      strcpy(ref[num].word,t);
      ref[num].lineNum = l;
      return 1;
   }
   else return 0;
}

void swap(REF *a,REF *b){
   REF t;
   t=*a; *a=*b; *b=t;
}

int main(){
   int line,wordNum=0;
   char *p,*s;
   char tmp[MAXLEN];
//   freopen("crossref.out","w",stdout);
   gets(p=buf);
   for(line=1;*p!='\0';line++){
      while(*p!='\0'){
         while(*p==' ')p++;
         sscanf(p,"%s",tmp);
         if(saveWord(tmp,wordNum,line))
            wordNum++;
         p+=strlen(tmp);
         while(*p==' ')p++;
      }
      gets(p=buf);
   }
//   sortRef();
   int i,j;
   for(i=0;i<wordNum;i++){
      for(j=wordNum-1;j>i;j--){
         if(strcmp(ref[j].word,ref[j-1].word)<0)
            swap(&ref[j],&ref[j-1]);
         else if(strcmp(ref[j].word,ref[j-1].word)==0
               && ref[j].lineNum < ref[j-1].lineNum)
            swap(&ref[j],&ref[j-1]);
      }
   }
//   printRef();
if(wordNum!=0){
   printf("%s:%d",ref[0].word,ref[0].lineNum);
   for(i=1;i<wordNum;i++){
      if(strcmp(ref[i].word,ref[i-1].word)==0){
         if(ref[i].lineNum!=ref[i-1].lineNum)
            printf(",%d",ref[i].lineNum);
      }
      else
         printf("\n%s:%d",ref[i].word,ref[i].lineNum);
   }
   printf("\n");
}
   system("pause");
   return 0;
}
