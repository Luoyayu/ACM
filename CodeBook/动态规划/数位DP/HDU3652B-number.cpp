#include<bits/stdc++.h>
//数位第三弹找出B数个数即x中含有“13” 且x%13=0; n<=1000000000;
using namespace std;
const int maxn =12;
int dp[maxn][maxn][13][2];//设计状态dp[位数][前一个数][mod 13结果][是否含1];
int a[maxn];
int dfs(int pos,int pre,int mod,bool inc,bool limit)
{
    if(pos==0) return !mod && inc;//返回能被13整除的即mod = 0
    if(!limit && ~dp[pos][pre][mod][inc])
        return dp[pos][pre][mod][inc];

    int ans=0, m=0;
    int up= limit? a[pos]: 9;
    for(int i=0; i<=up; i++)
    {
        m=(mod*10+i)%13;
        if( pre==1&&i==3 )
             ans+=dfs(pos-1, i, m, true, limit&&i==up);
        else
             ans+=dfs(pos-1, i, m, inc, limit&&i==up);
    }
    return limit? ans: dp[pos][pre][mod][inc]=ans;
}

int solve(int n)
{
    int pos = 0;
    while(n)
    {
        a[++pos]=n%10;
        n/=10;
    }
    return dfs(pos,0,0,false,true);
}
int main()
{

    int n;
    memset(dp,-1,sizeof dp);
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",solve(n));
    return 0;
}
