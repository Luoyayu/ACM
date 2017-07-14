int n;
    while(scanf("%d",&n)!=EOF)
    {
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(a<60||b<60||c<60)
                continue;
            if((a+b+c)>=240)
                cnt++;
        }
        printf("%d\n",cnt);
    }
