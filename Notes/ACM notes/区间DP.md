### 区间DP

[TOC]

####   1.[POJ 1651 Multiplication Puzzle ](http://poj.org/problem?id=1651)

*题意描述:*

给出序列$a$,求出最小得分—— 取出的数*左边的数*右边的数 (不能取两边)，实质为矩阵链乘变形，设$dp[i][j]$为取光$(i,j)$之间的元素所得的最小值, $k$为区间$(i,j)$最后取出的元素，这样转移就可以维持状态方程的一致性$cmin(dp[i][j], DP(l,k)+DP(k,r)+a[k]*a[l]*a[r])$，因为如果$k$为第一次取出的元素的话不好确定$k$左右的临近元素

写法区间DP入门题之记忆化写法

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
const int inf = 0x3f3f3f3f;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int dp[maxn][maxn];
int a[maxn];
int DP(int l, int r) {
    if(~dp[l][r])return dp[l][r];
    if(r-l==1) return dp[l][r] = 0;
    dp[l][r] = inf;
    for(int k=l+1; k<=r-1; ++k)//枚举最后取出的点
        dp[l][r] = min(dp[l][r], DP(l,k)+DP(k,r)+a[k]*a[l]*a[r]);
    return dp[l][r];
}
int main() {
    int n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    memset(dp,-1,sizeof dp);
    return !printf("%d\n",DP(1,n));
}
```

之迭代写法

```cpp
#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int dp[105][105];
int a[105];
int main() {
    int n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    memset(dp,0,sizeof(dp));
    for(int len = 2;len <= n-1; len++) {
        for(int i=1;i<=n-len;i++) {
            int j=i+len;
            if(len==2) dp[i][j] = a[i]*a[i+1]*a[i+2];
            else {
                for(int k=i+1;k<j;k++) {
                    if(dp[i][j]==0)
                        dp[i][j] = dp[i][k]+dp[k][j]+a[i]*a[k]*a[j];
                    else
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
                }
            }
        }
    }return !printf("%d\n",dp[1][n]);
}
```

####2. [HDU 5115 Dire Wolf](http://acm.hdu.edu.cn/showproblem.php?pid=5115) 

*题目描述*：

给出n只狼, 每只狼有基础攻击和给相邻的带去增益攻击,问以一个怎样的消灭顺序能得到最少的伤害

*解法*：

区间$DP$，设$dp[i][j] $为消灭区间$(i,j)$所有狼收到的最小伤害,那么当$i=j+1$时$dp[i][j]=0$

设$k$为区间$(i,j)$最后取出的元素，递归处理$[l,r]$区间的每一个元素$cmin(dp[i][j],DP(l,k)+DP(k,r)+a[k]+b[l]+b[r])$

代码：

```cpp

#include<bits/stdc++.h>
using namespace std;
const int maxn = 222;
const int inf = 0x3f3f3f3f;
#define cmin(a,b) a=min(a,b);
typedef long long ll;
ll a[maxn],b[maxn],dp[maxn][maxn];
ll DP(int l,int r)
{
    if(~dp[l][r]) return dp[l][r];
    if(r-l==1) return 0; //递归边界
    dp[l][r] = inf;
    for(int k=l;k<=r;k++)//枚举最后取出的元素k
        cmin(dp[l][r],DP(l,k)+DP(k,r)+a[k]+b[l]+b[r]);
    return dp[l][r];
}
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        memset(dp,-1,sizeof(dp));
        a[0] = a[n+1] = b[0] = b[n+1] = 0;
        printf("Case #%d: %lld\n",kase,DP(0,n+1));
    }return 0;
}
```

#### 3. [HDU 4570Multi-bit Trie](http://acm.hdu.edu.cn/showproblem.php?pid=4570) 

题目描述：

$LPM$最长前缀匹配从转发信息库$(FIB)$中找出匹配输入数据包的目的地址输出相应的$ Next  \ Hop \ information$
变态题意：一个长度为$n$的数列将其分成若干段每一段长度要求小于$20$， $$\sum(a_i * (2^{b_i}))$$ $ b_i$是每一段的长度，$ a_i$是每一段的首元素的值。样例$n=7,A=\left \{1,2,4,4,5,4,3 \right \}$的最佳分法是$1 \ 2 \ 4 \ | \ 4 \ 5\ |\  4\  |\  3$ ,这样的$\sum=1*8+4*4+4*2+3*2=38$

解法：区间$DP$ ，序列的长度不超过64，每层长度不大于20

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//题意比较绕大意是给出序列a,问一种划分n层使得\sum a_i*(2^(b_i))的值最小
//其中a_i是每一层首元素的值,b_i是每一层的元素个数
//其中要求每一层的元素个数小于20，那么初始化的时候可以对于j-i<20,dp[i][j]=a[i]*(1LL<<(j-i+1))
//状态转移方程dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]); //即i到j层的和是等于由i到k层加上k+1到j层递归形成的
const int maxn =65;
const int inf = 0x3f3f3f3f;
#define cmin(a,b) a=min(a,b);
ll a[maxn],dp[maxn][maxn]; // 一种写法：设dp[i][j]表示从第i层到第j层的代价
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n); //最多分n层
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                if(j-i+1<=20) dp[i][j]=a[i]*(1LL<<(j-i+1));//对于分的层数小于20的
                else dp[i][j]=inf;

        for(int l=1;l<=n;l++)
            for(int r=l;r<=n;r++) //枚举[l,r]
                for(int k=l;k<=r;k++)//枚举k位置
                    cmin(dp[l][r], dp[l][k]+dp[k+1][r]);
        printf("%lld\n",dp[1][n]);
        // printf("%lld\n",DP(1,n));
    }return 0;
}

```



#### 4. [CF 149 D Coloring Brackets](http://codeforces.com/problemset/problem/149/D)

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
//题意:给出括号序列染色要求
/*1.括号要么不被染色要么染成红或蓝色
 *2.相邻的括号要染色保持不同
 *3.相匹配的括号有且只有一个被染色
 */
//dp[l][r][x][y]为[l,r]表示给[l,r]染色且端点l染x色，右端点r染y色 <0,1,2>分别为<plain, red, blue>
//if <l,r> is matched ,那么由去掉这个嵌套的dp[l+1][r-1][x][y]转移出dp[l][r][x][y]枚举l+1,r-1的颜色
/*i->l+1; j->r-1;
 * if(i!=1) dp[l][r][1][0]=(dp[l][r][1][0] + dp[l+1][r-1][i][j])%mod;
 * if(i!=2) dp[l][r][2][0]=(dp[l][r][2][0] + dp[l+1][r-1][i][j])%mod;
 * if(j!=1) dp[l][r][0][1]=(dp[l][r][0][1] + dp[l+1][r-1][i][j])%mod;
 * if(j!=2) dp[l][r][0][2]=(dp[l][r][0][2] + dp[l+1][r-1][i][j])%mod;
 */
//if <l,r> isn't matched,那么可以找到和l匹配的括号位置mid,求出dp[l][mid][][]和dp[mid+1][r][][]枚举l,mid,mid+1,r这四个位置的颜色i,j,x,y 有转移方程
//if(j*x==0||j!=x) dp[l][r][i][y]=(dp[l][r][i][y] + dp[l][mid][i][j] * dp[mid+1][r][x][y]%mod)%mod;
typedef long long ll;
const int maxn = 700 + 7;
const int mod = int(1e9 + 7);
int belong[maxn];
ll dp[maxn][maxn][3][3];
char ss[maxn];
void dfs(int l, int r)
{
    if(r-l==1)
    {
        dp[l][r][0][1] = dp[l][r][0][2]=dp[l][r][1][0]=dp[l][r][2][0] = 1;
        return ;
    }
    if(belong[l]==r)
    {
        dfs(l+1,r-1);//一直递归到小区间处理
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(i!=1) dp[l][r][1][0]=(dp[l][r][1][0] + dp[l+1][r-1][i][j])%mod;
                if(i!=2) dp[l][r][2][0]=(dp[l][r][2][0] + dp[l+1][r-1][i][j])%mod;
                if(j!=1) dp[l][r][0][1]=(dp[l][r][0][1] + dp[l+1][r-1][i][j])%mod;
                if(j!=2) dp[l][r][0][2]=(dp[l][r][0][2] + dp[l+1][r-1][i][j])%mod;
            }
    }
    else
    {
        int mid = belong[l];
        dfs(l,mid);dfs(mid+1,r);
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        for(int x=0;x<3;x++)
        for(int y=0;y<3;y++){//<i,j>, <x,y>
        if(j*x!=0 && j==x) continue;
        dp[l][r][i][y]=(dp[l][r][i][y] + dp[l][mid][i][j] * dp[mid+1][r][x][y]%mod)%mod;
       }
    }
}
int main()
{
    while(scanf("%s",ss)!=EOF) {
        int len = strlen(ss);
        for(int i=0;i<len;i++)//处理匹配
            if(ss[i]=='(') {
                int cnt = 0;
                for(int j=i;j<len;j++){
                    if(ss[j] =='(') cnt++;
                    else cnt--;
                    if(cnt==0) {
                        belong[i] = j;
                        break;
                    }
                }
            }

        memset(dp,0, sizeof(dp));
        dfs(0,len-1);
        ll ans = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ans = (ans + dp[0][len-1][i][j])%mod;
        printf("%lld\n",ans);
    }return 0;
}
```



#### 5. [UVA 10003 Cutting Sticks](https://vjudge.net/problem/UVA-10003)

题目描述：

给出长度为N的木条，要在i-th点位置切割，每次切割的代价是当前切割块的木条的长度。给出要切割的点问最小的花费。

解法：

区间DP，对于区间的划分顺序影响总结果用区间DP，带上代价划分

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int inf = 0x3f3f3f3f;
#define cmin(a,b) a=min(a,b);
int a[maxn],dp[maxn][maxn];//设dp[i][j]为切割第i到第j位置的最小代价
int DP(int l,int r)//区间(i,j)
{
    if(~dp[l][r]) return dp[l][r];
    if(r-l==1) return 0;
    dp[l][r] = inf;
    for(int k=l+1;k<=r-1;k++)
        cmin(dp[l][r],DP(l,k)+DP(k,r)+a[r]-a[l]);
    return dp[l][r];
}
int main()
{
    int n,L;
    while(scanf("%d",&L)!=EOF&&L)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        a[0]=0,a[n+1]=L;
        printf("The minimum cutting is %d.\n",DP(0,n+1));//注意输出格式
    } return 0;
}
```











