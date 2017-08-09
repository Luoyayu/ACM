//2010多校~数位DP
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e8;
int alen;//删去前导0的子串长度
int opcnt;//原串长度
//题意:给定数字趋势求在[A,B]内满足的数个数,例如有/-\ 123321就满足这种趋势
string A,B,str;
int dp[110][110][100];//设计状态dp[pos][pre][k]为当前第i位,上一个位为j,匹配关系到了k
int dig[110];
void sub(string& ori)//大数-1
{
    int len = ori.size();
    if(ori[len-1]>'0')
        ori[len-1] -= 1;
    else
    {
        int i = len-1;
        while(i>=0&&A[i]=='0') 
            ori[i]='9',i--;
        A[i]-=1;
    }
}
bool check(int x,int y,char op)
{
    if(op == '/') return x<y;
    else if(op == '-') return x==y;
    else return x>y;
}
int dfs(int pos,int lead, int cnt, int pre,bool limit)
{
    if(pos==alen) return cnt == opcnt;//查看匹配是否结束
    if(!limit && !lead && ~dp[pos][cnt][pre]) return dp[pos][cnt][pre];
    int up = limit ? dig[pos] : 9;
    int ans = 0;
    for(int i = 0; i <= up; i++)
    {
        if(lead) ans+= dfs(pos+1,lead && i==0, 0, i, limit && i==up);
        else
        {
            if(cnt<opcnt && check(pre,i,str[cnt]))//满足当前匹配(pre str[cnt] i)的节点
                ans+=dfs(pos+1,0,cnt+1,i,limit && i==up);//移到下一个匹配位置
            else if(cnt>0 && check(pre,i,str[cnt-1]))//仍然还是满足当前匹配
                ans+=dfs(pos+1, 0, cnt, i, limit && i==up);
        }
        ans%=mod;
    }
    if(!limit && !lead) dp[pos][cnt][pre] = ans;
    return ans;
}
int solve(string a)//同时除掉前导零
{
    memset(dp,-1,sizeof dp);
    alen = a.size();
    int st = 0;
    while(a[st]=='0') st++;
    for(int i=st;i<alen;i++)
        dig[i]=a[i]-'0';
    return dfs(st,1,0,0,1);      
}
int main()
{
    while(cin>>str)
    {
        opcnt = str.size();
        cin>>A>>B;sub(A);
        printf("%08d\n",(solve(B)-solve(A)+mod)%mod);
    }
    return 0;
}