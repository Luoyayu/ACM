***DP之数位DP的总结***

数位DP是一种基于每一位数字进行状态转移的DP

这里总结下比赛中做过的好题

[TOC]

### Template

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 222;
int dig[maxn];
int dp[maxn][10][c1][c2]
int dfs(int pos, int pre, int inc1,int inc2,....int lim, int led)//记忆化
{
    if(pos==-1) return inc1==c1 && inc2==c2&&...&&lead;//处理到个位时需单独判断
  	if(!lim&& ~dp[pos][pre][c1][c2]) return dp[pos][pre][c1][c2];
  	int up = lim ? dig[pos] : 9;
  	for(int i=led?1:0;i<=9;i++)//考虑是否能枚举0
  	{
      	//状态转移
      	ans += dfs(pos-1,i,newc1,newc2...,i==up?lim,led&&i==0);//区分前导0
  	}
  	return !lim && lead ? dp[pos][pre][c1][c2] = ans : ans;
}
/*几个注意点:
 *1)前置前导零
*/
int solve(int x)//常规处理 123-> dig[]={3,2,1}
{
    int pos = 0;
  	while(x)
        dig[pos++] = x%10, x/=10;
  	return dfs(pos-1,-1,false,false,...,true,false);
}
int solve(char *x)//处理大数
{
    int len = strlen(x);
  	for(int i=0;x[i];i++)
		dig[len-i-1] = x[i] - '0';
  	return dfs(len-1,-1,false,false,...true,false);
}
void Bigsub(char *o)//大数-1
{
    int len = strlen(o);
  	if(o[len-1]>'0') o[len-1]-=1;
  	else//借位
    {
        int pos = len -1;
      	while(pos>=0&&o[pos]=='0')
          o[i]='9', pos--;
      	o[pos] -= 1;
    }
}
bool check()//在记忆化中较为复杂的校检——例:2010多校 数字的趋势
{
    if-else(){} return fasle-true;
}
```

### Beginner level

#### HDU 2089 不62 

```c++
#include<bits/stdc++.h>
using namespace std;
int dp[22][2], dig[22];
int dfs(int pos,int pre,int inc,bool lim)
{
    if(pos==-1) return 1;
    if(!lim && ~dp[pos][inc]) return dp[pos][inc];
    int up = lim ? dig[pos]:9;
    int ans = 0;
    for(int i=0;i<=up;i++)
    {
        if(i==4||i==2&&pre==6)continue;
        ans += dfs(pos-1,i,i==6,lim&i==up);
    }
    return !lim?dp[pos][inc] = ans : ans;
}
int cal(int x)
{
    int pos = 0;
    while(x)
        dig[pos++] = x % 10, x/= 10;
    return dfs(pos-1,-1,false,true);
}
int main()
{
    int n,m;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
        printf("%d\n",cal(m)-cal(n-1));
    return 0;
}
```



#### HDU 3652 B-number

```c++
#include <bits/stdc++.h>
using namespace std;
#define clr(a,b) memset(a,b,sizeof(a))
int dp[12][10][2][13];//dp[位数][pre][前面是否已经含13][mod 13结果]
int dig[12];
int dfs(int pos,int pre, bool inc,int mod,bool lim)//inc前面是否已经含有13;mod 前面mod 13结果
{
    if(pos==-1) return !mod&&inc;//判断到个位时来的总判断
    if(!lim && ~ dp[pos][pre][inc][mod]) return dp[pos][pre][inc][mod];
    int up = lim ? dig[pos]: 9;
    int ans = 0, m = 0;//如果前面已经含有13这个串后面就不用考虑了!
    for(int i=0;i<=up;i++)
    {
        m = (mod*10+i)%13;
        if(pre==1&&i==3) ans += dfs(pos-1, i, true, m, lim && up==i);
        else ans += dfs(pos-1, i, inc, m, lim && up==i);
    }
    return !lim?dp[pos][pre][inc][mod]=ans:ans;
}
int cal(int x)
{
    int pos = 0;
    while(x) dig[pos++] = x % 10, x/=10;
    return dfs(pos-1,-1, false,0,true);
}
int main()
{
    int n;clr(dp,-1);
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",cal(n));
    return 0;
}
```



#### HDU 3709 Balanced Number 

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
typedef long long ll;
//通过枚举18个可能的支点计算平衡数,注意平衡位置为0且左右皆为0的情况只考虑1次!
//首先观察平衡的数字的特点是那垓位的数字乘上位数-平衡位置求和为故,记录下这个计算值即可
ll dp[maxn][maxn][5000];//状态设计dp[pos][平衡位置][平衡值] 平衡值==0说明是平衡数
int dig[maxn];
ll dfs(int pos, int o, int tot, int lim)
{
    if(pos== -1) return !tot;
    if(!lim && ~dp[pos][o][tot]) return dp[pos][o][tot];
    int up = lim? dig[pos] : 9;
    ll ans = 0;
    for(int i=0;i<=up;i++)
        ans += dfs(pos-1,o,(pos-o)*i+tot,i==up&&lim);
    return !lim ? dp[pos][o][tot] = ans :ans;
}
ll cal(ll x)
{
    int pos = 0;
    while(x) dig[pos++] = x % 10, x/=10;
    ll ans = 0;
    for(int i=0;i<=pos-1;i++)
        ans += dfs(pos-1,i,0,true);
    return ans-pos+1;//注意平衡位置为0且左右皆为0的情况只考虑1次!
}
int main()
{
    int t; scanf("%d",&t);
    memset(dp,-1, sizeof(dp));
    while(t--)
    {
        ll n,m;scanf("%lld%lld",&n,&m);
        printf("%lld\n",cal(m)-cal(n-1));
    }
    return 0;
}
```

#### HDU 4507 恨7不成妻 

```c++
#include <bits/stdc++.h>
using namespace std;
//情况比较多 1.含7 2.数和为7的倍数 3.数为7的倍数
//求出平方和？_ ?
typedef long long ll;
const int mod = 1e9 +7;
int dig[22];
struct DP
{
    ll cnt,sum, sqsum;
    DP(){}
    DP(ll cnt,ll sum,ll sqsum):cnt(cnt),sum(sum),sqsum(sqsum){}
};
//数位DP的状态设计就是对于数字进行位上分类
//数位DP表面上从高位到地位处理实则是从低位到高位进行回溯!
DP dp[22][7][7];//设计状态dp[pos][和%7][%7]时发现dp的值要处理的过多一般dp存的时满足条件的数目现在结构体存之,
// 同时保存到该前缀为止的位数之和,平方之和,满足条件的数的个数以便操作
ll Base[22]={1};
inline void init()//基数
{
    memset(dp,-1, sizeof(dp));
    for(int i=1;i<=22;i++)
        Base[i] = (Base [i-1]) *10 %mod;
}
DP dfs(int pos,int inc1,int inc2,bool lim)//c1: 之和%7, c1: %7
{
    if(pos==-1) return DP(inc1&&inc2,0,0);
    if(!lim && ~ dp[pos][inc1][inc2].cnt) return dp[pos][inc1][inc2];
    int up = lim? dig[pos]:9;
    DP ans = DP(0,0,0);
    for(int i=0;i<=up;i++)
    {
        if(i==7) continue;
        //以下及回溯的过程
        //从低位出发例如 432 -> 4321 回溯就是   1->12 1->13...123->1234
        //我们还是倒着写 比如   @321 -> 1231 回溯时选定高位 那么平方的答案就是 (高位*高位对应的基数 + 除了高位的和)^2 = ret.cnt* (i * base[pos] + ret.sum)^2 = i*i*base[pos]*base[pos] + ret.sum ^ 2 + 2* i *base[pos] 其中 ret.sum^2*cnt = ret.sqsum 其余的就好处理了 
        DP ret = dfs(pos-1, (inc1+i)%7, (inc2*10+i)%7, lim && i==up); 
        ans.cnt = (ans.cnt + ret.cnt) % mod;
        ans.sum += (((Base[pos]*i)%mod*ret.cnt)%mod + ret.sum) % mod;
        ans.sum %= mod;
        ans.sqsum += (ret.sqsum + ((2*Base[pos]*i)%mod*ret.sum)%mod) %mod;//这里需要格外注意
        ans.sqsum %= mod;
        ans.sqsum += ((i*Base[pos]*i%mod)*Base[pos]%mod * ret.cnt) %mod;
        ans.sqsum %= mod;
    }
    return !lim?dp[pos][inc1][inc2] = ans : ans;
}

ll cal(ll x)
{
    int pos = 0;
    while(x) dig[pos++] = x %10, x/=10;
    return dfs(pos-1, 0,0,true).sqsum;
}
int main()
{
    init();
    int t; scanf("%d",&t);
    while(t--)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",(cal(m)-cal(n-1)+mod)%mod);
    }
    return 0;
}

```



####HDU 4734 F(x)

description:define F(X) 为X各位数乘以二进制基数之和,求在[0,B]中不大于F(A)的正整数个数

```cpp
#include <bits/stdc++.h>
using namespace std;
int base[10];
int dig[10];
int dp[10][55000];//设计状态为dp[pos][j]为当前pos位不大于j的个数
int FA;
int F(int x)
{
    int ret=0, cnt=0;
    while(x)
    {
        ret += (x%10)*base[cnt++];
        x/=10;
    }
    return ret;
}
int dfs(int pos, int inc, bool lim)//inc = F(A) - F(x);
{
    if(pos == -1) return FA-inc>=0 && inc>=0;
    if(FA - inc<0) return 0;
    if(!lim && ~dp[pos][FA-inc]) return dp[pos][FA-inc];
    int up = lim?dig[pos]:9;
    int ans = 0;
    for(int i=0;i<=up;i++)
        ans += dfs(pos-1,inc+base[pos]*i,i==up && lim);
    return !lim?dp[pos][FA-inc] = ans : ans;
}
int cal(int x)
{
    int pos = 0;
    while(x) dig[pos++] = x % 10, x /= 10;
    return dfs(pos-1,0,true);
}
int main()
{
    base[0]=1;memset(dp,-1, sizeof(dp));
    for(int i=1;i<=10;i++) base[i] = base[i-1]<<1;
    int t,kase=1;scanf("%d",&t);
    while(t--)
    {
        int A,B;scanf("%d %d",&A,&B);
        FA = F(A);
        printf("Case #%d: %d\n",kase++,cal(B));
    }
    return 0;
}
```



#### HDU 5179 beautiful number 

```c++

```



####HDU6148Valley Number 

```cpp

```



#### HDU 3886 Final Kichiku “Lanlanshu“

```cpp

```

#### BZOJ [1026 [SCOI2009] windy数](http://www.lydsy.com/JudgeOnline/problem.php?id=1026)

Description: data range:= 2e9, 定义windy数为不含前导0且相邻两个数字之差至少为2的non-negative,处理好前导零即可

```cpp

```



#### POJ [3252 Round Numbers](http://poj.org/problem?id=3252)

```cpp

```



#### BZOJ 2757 [SCOI2012] Blinker的仰慕者

```cpp

```



#### HDU 4352 [XHXJ's LIS](http://acm.hdu.edu.cn/showproblem.php?pid=4352)








