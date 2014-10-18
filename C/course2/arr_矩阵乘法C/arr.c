#include<stdio.h>
#define MAX 20000
int a[200][200],b[200][200],c[200][200];

int main(){
   int i=0,j=0,kn;
   char str[1000], *p;
   int num,n=0,m=0,k=0,mk=1;
   freopen("arr.in","r",stdin);
   gets(str);
   for(p=str;*p!='\0';){
      while(*p!=' '&&*p!='\0')p++;
      while(*p==' ')p++;
      k++;
   }
   while(gets(str)) mk++ ;
   m=mk-k;
   fclose(stdin);
   freopen("arr.in","r",stdin);
   for(i=0;i<m;i++)gets(str);
   gets(str);
   for(p=str;*p!='\0';){
      while(*p!=' '&&*p!='\0')p++;
      while(*p==' ')p++;
      n++;
   }
   fclose(stdin);
   freopen("arr.in","r",stdin);
   for(i=0;i<m;i++)
      for(j=0;j<k;j++)
         scanf("%d",&a[i][j]);
   for(i=0;i<k;i++)
      for(j=0;j<n;j++)
         scanf("%d",&b[i][j]);
   fclose(stdin);
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
