//杨辉三角
for(int i=0;i<=n;++i)
    for(int j=*c[i]=1;j<=i&&j<=m;++j)
        c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;

//卢卡斯组合数取模
