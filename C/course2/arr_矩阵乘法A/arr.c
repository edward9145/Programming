#include<stdio.h>
#define A 0
#define B 1
int a[200][200],b[200][200],c[200][200];

int main(){
   int i=0,j=0,kn;
   char str[1000], *p;
   int num,n,m,k;
   int ab = A;
   freopen("arr.in","r",stdin);
   for(i=0; gets(str)!=NULL; i++){
        if (str[0]=='\0') {
            m= i;
            i= -1;
            ab= B;
            continue;
        }
        p=str;
        for (j=0;*p!='\0';j++){
            if(ab==A)
               sscanf(p, "%d", &a[i][j]);
            else
               sscanf(p, "%d", &b[i][j]);
            while (*p != ' ' && *p != '\0') p++;
            while (*p == ' ') p++;
        }
        if (i == 0 && ab == B) n = j;
    }
   k= i;
   /*
   printf("%d %d %d\n",m,k,n);
   for(i=0;i<m;i++){
      for(j=0;j<k;j++)
         printf("%15d",a[i][j]);
      printf("\n");
   }
   for(i=0;i<k;i++){
      for(j=0;j<n;j++)
         printf("%15d",b[i][j]);
      printf("\n");
   }
   */
   for(i=0;i<m;i++)
      for(j=0;j<n;j++)
         c[i][j]=0;
         
   for(i=0;i<m;i++)
      for(j=0;j<n;j++)
         for(kn=0;kn<k;kn++)
            c[i][j]+=a[i][kn]*b[kn][j];

   for(i=0;i<m;i++){
      for(j=0;j<n;j++){
         printf("%15d", c[i][j]);
      }
      printf("\n");
   }
//while(1);
//system("pause");
   return 0;
}
