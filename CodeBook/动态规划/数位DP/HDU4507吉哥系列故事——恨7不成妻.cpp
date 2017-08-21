#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int MOD = 1E9 + 7;
struct Node
{
    LL cnt,sum,sqsum;
    Node(){}
    Node(LL cnt, LL sum, LL sqsum):cnt(cnt), sum(sum), sqsum(sqsum){}
}dp[20][7][7];//设计状态dp[当前位数][位数之和%7][数值%7]
int a[20];
LL js[20];

Node dfs(int pos, int pra, int prb, bool limit)//pra:位数之和%7; prb:数值%7
{
    if(pos == -1)
        return Node(pra!=0 && prb!=0, 0, 0);
    if(!limit && ~dp[pos][pra][prb].cnt) return dp[pos][pra][prb];
    int up = limit?a[pos]:9;
    Node ans = Node(0, 0, 0);
    for(int i=0; i<=up; i++)
    {
        //sum[new_state]=Σ{ sum[old_state]+(i)*(its_base)*cnt[old_state] }
        if(i != 7)
        {
            Node tmp = dfs(pos-1, (pra+i)%7, (prb*10+i)%7, limit && i==up);
            ans.cnt = (ans.cnt + tmp.cnt) % MOD;
            ans.sum += (((js[pos]*i)%MOD*tmp.cnt)%MOD + tmp.sum) % MOD;
            ans.sum %= MOD;
            ans.sqsum += (tmp.sqsum + ((2*js[pos]*i)%MOD*tmp.sum)%MOD) %MOD;
            ans.sqsum %= MOD;
            ans.sqsum += ((i*js[pos]*i%MOD)*js[pos]%MOD * tmp.cnt) %MOD;
            ans.sqsum %= MOD;
        }
    }
    if(!limit)
        dp[pos][pra][prb] = ans;
    return ans;
}

inline void init()
{
    js[0] = 1;
    for(int i=1; i<20; i++)
        js[i] = (js[i-1]*10) % MOD;
}

LL solve(LL n)
{
    int pos = 0;
    while(n)
    {
        a[pos++] = n%10;
        n /= 10;
    }
    Node ans = dfs(pos-1, 0, 0, true);
    return ans.sqsum;
}

int main()
{
    int T;scanf("%d", &T);
    init();
    memset(dp, -1, sizeof(dp));
    while(T--)
    {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", (solve(r) - solve(l-1) + MOD) % MOD);//
    }
    return 0;
}