#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    return b==0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("gcd = %d\n", gcd(a,b));
    printf("lcm = %d\n", lcm(a,b));
    system("pause");
    return 0;
}
