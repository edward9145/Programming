/*
test data:
3x5 + 5x3 + 6
9x6 + 2x5 + 6x3 + x2 + 6
*
*/
#include<stdio.h>
#define POWER 400
#define FOMULA 1
#define OPERATOR 2
int type(char s[]);
void set(int f[], char s[], int sign);
int isExist(char s[], char c);
void print(int f[]);
void calc(int a[], int b[], int c[], char op);
void read(int a[]);
int main(){
   int A[POWER]={0};
   int B[POWER]={0};
   int C[POWER]={0};
   char op=0;
   freopen("poly.in","r",stdin);
   read(A);
   read(B);
   op=getchar();
   //print(A);
   //print(B);
   calc(A,B,C,op);
   print(C);
//while(1);   
system("pause");
   return 0;
}

int type(char s[]){
   if(strlen(s)==1)
      if(s[0]=='+'||s[0]=='-')
         return OPERATOR;
   return FOMULA;
}

void set(int f[],char s[],int sign){
   int A,N;
   char c;
   if(isExist(s,'x')){
      if(s[strlen(s)-1]=='x'){
         sscanf(s,"%d%c",&A,&c);
         f[1]=A*sign;
      }
      else if(s[0]=='x'){
         sscanf(s,"%c%d",&c,&N);
         f[N]=sign;
      }
      else{
          sscanf(s,"%d%c%d",&A,&c,&N);
          f[N]=A*sign;
      }
   }
   else{
      sscanf(s,"%d",&A);
      f[0]=A*sign;
   }
}

int isExist(char s[], char c){
   int i;
   for(i=0;i<strlen(s);i++)
      if(s[i]==c)
         return 1;
   return 0;
}

void print(int f[]){
   int i;
   for(i=POWER-1;(i>0)&&(f[i]==0);i--);
   if(i==0) printf("%d",f[i]);
   else if(i==1){
      if(f[i]==1) printf("x");
      else if(f[i]==-1)printf("-x");
      else printf("%dx",f[i]);
   }
   else if(i > 0){
      if(f[i]==1) printf("x%d",i);
      else if(f[i]==-1)printf("-x%d",i);
      else if(f[i]!=0) printf("%dx%d",f[i],i);
   }
   
   for(i=i-1;i>=0;i--){
      if(f[i]!=0){
         if(i==0){
            if(f[i]==1) printf(" + 1");
            else if(f[i]==-1) printf(" - 1");
            else if(f[i]>1) printf(" + %d",f[i]);
            else printf(" - %d",-f[i]);
         }
         else if(i==1){
            if(f[i]==1) printf(" + x");
            else if(f[i]==-1) printf(" - x");
            else if(f[i]>1) printf(" + %dx",f[i]);
            else printf(" - %dx",-f[i]);
         }
         else{
            if(f[i]==1) printf(" + x%d",i);
            else if(f[i]==-1) printf(" - x%d",i);
            else if(f[i]>1) printf(" + %dx%d",f[i],i);
            else printf(" - %dx%d",-f[i],i);
         }
      }
   }
   printf("\n");
}

void calc(int a[], int b[], int c[], char op){
   int i,j;
   if(op=='+'){
      for(i=0;i<POWER;i++)
         c[i]=a[i]+b[i];
   }
   else if(op=='-'){
      for(i=0;i<POWER;i++)
         c[i]=a[i]-b[i];
   }
   else{
      for(i=0;i<POWER;i++){
         if(a[i]!=0){
            for(j=0;j<POWER;j++){
               c[i+j]+=a[i]*b[j];
            }
         }
      }
   }
}

void read(int a[]){
    char ch = 0, s[100];
    int i, zf = 1, mi, xs;
    for(i=0;ch != '\n';){
        ch = getchar();
        if (ch == ' ') continue;
        if (ch != '-' && ch != '+' && ch != '\n')
            s[i++] = ch;
        else{
            s[i] = '\0';
            mi = xs = 1;
            if (strchr(s, 'x') != NULL){
                if (s[0] == 'x') sscanf(s, "x%d", &mi);
                else if (s[i-1] == 'x') sscanf(s, "%dx", &xs);
                else sscanf(s, "%dx%d", &xs, &mi);
            }
            else {sscanf(s, "%d", &xs); mi = 0;}
            a[mi] = xs * zf;
            if (ch == '-') zf = -1;
            else if (ch == '+') zf = 1;
            i = 0;
        }
    }
/* my reading func
   int sig = 1;
   char tmp[20]={0},c=' ';
   
   while(c==' '){
      scanf("%s%c",tmp,&c);
      if(type(tmp)==FOMULA)
         set(A,tmp,sig);
      else
         sig = (tmp[0]=='+')? 1:-1;
   }c=' ';
   while(c==' '){
      scanf("%s%c",tmp,&c);
      if(type(tmp)==FOMULA)
         set(B,tmp,sig);
      else
         sig = (tmp[0]=='+')? 1:-1;
   }
   while(op!='-' && op!='+' && op!= '*')
      op=getchar();
*/ 
}
