main(a, b){
    scanf("%d %d", &a, &b);
    b?main(b, a%b):printf("%d\n", a);
}
