#include <bits/stdc++.h>
//题意：
using namespace std;
const int maxn=  2015;
const int inf = 0x3f3f3f3f;
int w[maxn];
int dp[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n-1;i++) scanf("%d",&w[i]);
        for(int i=1;i<n-1;i++) w[i] -= w[0], dp[i] = -inf;
        dp[0] = 0;

        for(int i=1;i<=n-2;i++)
            for(int se=i;se<=n-2;se++)
                dp[se] = max(dp[se],dp[se-i]+w[i]);
        printf("%d\n",dp[n-2]+w[0] * n);
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long LL;
const int maxn=1e6+7;

int se[maxn],pre[maxn],nxt[maxn],del[maxn];
set<int>st;
vector<int>tmp;

int main()
{
    int t,n;cin>>t;
    while(t--)
    {
        memset(del,0,sizeof del);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   
          scanf("%d",se+i),pre[i]=i-1,nxt[i]=i+1,st.insert(i);
        nxt[0]=1,pre[n+1]=n,pre[1]=0,nxt[n]=n+1;
        se[0]=0,se[n+1]=maxn;
        while(st.size())
        {
            tmp.clear();
            for(auto &x:st)
            {
                int Next=nxt[x],Pre=pre[x];
                if(se[Pre]>se[x])  tmp.PB(Pre),tmp.PB(x);
                if(se[x]>se[Next]) tmp.PB(x),tmp.PB(Next);
            }
            st.clear();
            for(auto &x:tmp)
                if(!del[x])
                {
                    int Next=nxt[x],Pre=pre[x];
                    nxt[Pre]=Next,pre[Next]=Pre;
                    st.insert(Pre);
                    del[x]=1;
                }
        }
        int cnt=0;
        for(int i=nxt[0];i!=n+1;i=nxt[i])   cnt++;
        printf("%d\n",cnt);
        for(int i=nxt[0];i!=n+1;i=nxt[i])   printf("%d ",se[i]);
        printf("\n");
    }
    return 0;
}