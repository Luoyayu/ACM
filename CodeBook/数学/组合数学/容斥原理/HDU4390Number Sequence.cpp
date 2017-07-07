#include<bits/stdc++.h>
using namespace std;  
typedef long long LL;
const LL MOD = 1000000007 ; 
int n;  
LL c[505][505];  
vector<int>v;  
void getPrime_factor(int num)  //分解质因子
{  
    for(int i=2;i*i<=num;i++)  
    {  
        while(num%i==0)  
        {  
            num/=i;  
            v.push_back(i);  
        }  
    }  
    if(num>1) v.push_back(num);  
}  
void init()  
{  
    for(int i=0;i<=500;i++)  
    {  
        c[i][0]=c[i][i]=1;  
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;  
    }  
}  
LL getRaw(int n,int m)  
{  
    return c[m+n-1][n-1];  
}  
LL slove()  
{  
    int a[1005]={1},cnt=0;  
    sort(v.begin(),v.end());  
    for(int i=1;i<v.size();i++)  
    {  
        if(v[i]!=v[i-1]) a[++cnt]=1;  
        else a[cnt]++;  
    }  
    LL ans=1;  
    for(int i=0;i<=cnt;i++)  ans=(ans*getRaw(n,a[i]))%MOD;  
    //cout<<ans<<endl;  
    for(int i=1;i<n;i++)  
    {  
        LL tmp=c[n][i];  
        for(int j=0;j<=cnt;j++)  
        {  
            tmp=(tmp*getRaw(n-i,a[j]))%MOD;  
        }  
        if(i&1) ans=((ans-tmp)%MOD+MOD)%MOD;  
        else ans=(ans+tmp)%MOD;  
    }  
    return ans;  
}  
int main()  
{  
    init();  
    while(scanf("%d",&n)!=EOF)  
    {  
        v.clear();  
        for(int i=0;i<n;i++)  
        {  
            int k;  
            scanf("%d",&k);  
            getPrime_factor(k);  
        }  
        printf("%I64d\n",slove());  
    }  
    return 0;  
}  