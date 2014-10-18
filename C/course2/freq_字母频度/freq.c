#include<stdio.h>
typedef struct{
   char ch;
   long count;
}ALPHABET;
ALPHABET alphabet[26];

void swap(ALPHABET *a,ALPHABET *b){
   ALPHABET tmp;
   tmp=*a; *a=*b; *b=tmp;
}

int main(){
   char c;
   int i,j;
   int total=0;
   freopen("freq.in","r",stdin);
   freopen("freq.out","w",stdout);
   for(i=0;i<26;i++){
      alphabet[i].ch=i+'a';
      alphabet[i].count=0;
   }
   while((c=getchar())!=EOF)
      if(tolower(c)>='a' && tolower(c)<='z')
         alphabet[tolower(c)-'a'].count++;
         
   for(i=0;i<26;i++)
      for(j=25;j>i;j--)
         if(alphabet[j].count>alphabet[j-1].count)
            swap(&alphabet[j],&alphabet[j-1]);
   
   for(i=0;i<10;i++)
      printf("%c%d ",alphabet[i].ch,alphabet[i].count);
   for(;i<26 && alphabet[i].count==alphabet[i-1].count;i++)
      printf("%c%d ",alphabet[i].ch,alphabet[i].count);
      
   for(i=0;i<26;i++)
      total+=alphabet[i].count;
   printf("\n%d\n",total);
   
   fclose(stdin);
   fclose(stdout);
   return 0;
}
