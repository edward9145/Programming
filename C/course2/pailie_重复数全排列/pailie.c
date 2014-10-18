#include <stdio.h>

int main(){
    char str[200], selected[200];
    int l, i, j, tp;
    scanf("%str", str);
    l = strlen(str);
    for (i=0;i<l-1;i++){
        for (j=0;j<l-i-1;j++){
            if (str[j] > str[j+1]){
                tp = str[j];
                str[j] = str[j+1];
                str[j+1] = tp;
            }
        }
    }

    while (printf("%s\n", str)){
        memset(selected, 0, sizeof(selected));
        selected[str[l-1]] = 1;
        for (i=l-2;i>=0 && str[i]>=str[i+1];i--)
            selected[str[i]]++;
        if (i < 0) break;
        for (j=str[i]+1;!selected[j];j++);
        selected[str[i]]++;
        str[i++] = j;
        selected[j]--;
        for(j='0';j<='z';j++)
            while(selected[j]--)
               str[i++] = j;
    }
    system("pause");
    return 0;
}
