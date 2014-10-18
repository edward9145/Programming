#include <stdio.h>
int main()
{
    int k, x, m, n, i;
    double a1 = 1.0, ans;
    long long sum = 0, an = 1;
    char s[1000];
    freopen("sigma.in", "r", stdin);
    scanf("%d%d%d%d", &k, &x, &m, &n);
    for (i=0;i<n;i++){an *= x; sum += an;}
    sum *= k;
    for (i=0;i<m;i++) a1 /= (double)x;
    if (x-1) ans = (a1 - (double)x) / (double)(1 - x) * (double)k;
    else ans = k * (m + 1);
    sum += ans;
    ans -= (long long)ans;
    sprintf(s, "%.14f", ans);
    printf("%lld%s\n", sum, s+1);
    
    while(1);
}
