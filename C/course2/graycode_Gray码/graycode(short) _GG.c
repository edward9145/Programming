main(i,n){char *s,*a,b[55],m;
    for(;m=a=s,gets(s);){
        if (s[0] == '-'){ m = s[1]; a = s + 2; }
        n = strlen(a);
        b[0] = a[0];
        if (m=='g')
            for (i=1;i<n;i++) b[i] = ((a[i] - 48) ^ (a[i-1] - 48)) + 48;
        else
            for (i=1;i<n;i++) b[i] = ((a[i] - 48) ^ (b[i-1] - 48)) + 48;
        b[n] = '\0';
        printf("%s\n", b);
    }
}
