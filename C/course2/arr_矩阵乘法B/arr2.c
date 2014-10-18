#include <stdio.h>
char s[5000], *p;
int kk, n, m, k, i, j, a[200][200], b[200][200], c[200][200] = {0}, *x = a;
int main(){
    freopen("arr.in", "r", stdin);
    for (i=0;gets(s) != NULL;i++){
        if (s[0] == '\0') {
            m = i;  i = -1;  x = b;
            continue;
        }
        p = s;
        for (j=0;*p!='\0';j++){
            sscanf(p, "%d", x + 200 * i + j);
            while (*p != ' ' && *p != '\0') p++;
            while (*p == ' ') p++;
        }
        if (i == 0 && x == b) n = j;
    }
    k = i;
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
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            for (kk=0;kk<k;kk++)
                c[i][j] += a[i][kk] * b[kk][j];
    for (i=0;i<m;i++){
        for (j=0;j<n;j++) printf("%15d", c[i][j]);
        printf("\n");
    }
    
    while(1);
}
