//Multi-Contest 1- 6 (HDOJ6038)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
//题意:给出排列a=[0,n) b=[0,m)
//定义函数f 值域为a,定义域为b
//确定满足f(i)=b_{f(a_i)}的数量%mod i∈[0,n)
//思想:通过样例可以发现对于部分的a(0,1,2) 有b_b_b(f(i))=f(i){i∈部分a}
//只要确定a的部分的一个值,那么相应的另外(l-1)个映射(函数)值便可以确定下来
//这个部分a其实就是a的一个循环节与之对应的在b中的映射也应该是一个循环节
//如果上述成立的话b的循环节应该是a的循环节的长度或者是其因子
//那么只要对于a的每个循环节,看b的相应的循环节是否为a的循环节的因子,是的话
//ans =Σ(i=1~k) Σ(j|l_i) j*cal_j k表示a的循环节的个数,
//j表示b的一个长度为j的循环节,cal_j表示长度为j的循环节的个数
//l_i表示置换a中的第i个循环节的长度
//复杂度分析O(n+m)
const int mod = int(1e9+7);
int a[maxn],b[maxn];
bool vis[maxn];
vector<int>A;
vector<int>B;
int main()
{
    int n,m;
    int kase = 1;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<m;i++)scanf("%d",&b[i]);

        A.clear();B.clear();
        memset(vis, 0, sizeof(vis));

        for(int i=0;i<n;i++)
        {
            int cur = i,cnt = 1;
            if(vis[i]==0)
            {
                vis[i] = 1;
                while(i!=a[cur])
                {
                    cnt++;
                    cur = a[cur];
                    vis[cur]=1;
                }
                A.push_back(cnt);
            }

        }

        memset(vis,0, sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int cur = i,cnt=1;
            if(vis[i]==0)
            {
                vis[i]=1;
                while(i!=b[cur])
                {
                    cnt++;
                    cur = b[cur];
                    vis[cur]=1;
                }
                B.push_back(cnt);
            }
        }

        long long ans = 1;
        for(int i=0;i<A.size();i++)
        {
            long long tmp = 0;
            for(int j=0;j<B.size();j++)
                if(A[i] % B[j]==0)
                    tmp = (tmp+B[j])%mod;
            ans = (ans%mod)*(tmp%mod)%mod;
        }
        printf("Case #%d: %lld\n",kase++,ans);
    }
    return 0;
}