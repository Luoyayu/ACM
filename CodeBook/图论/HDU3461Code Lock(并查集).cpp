///HDU3461并查集+快速幂 思考
///题意有一个字母从a到z的密码锁,m个区间[L,R],区间内的齿轮可以同时变化,
///当一种密码经过有限次可以变化成另一种时则他们是同一个类型,求有多少个类型
///懵,如果没有联动区间的话答案是26^n,如果增加一个联动区间则为26^(n-1)
///因为在这个区间内的26中情况数相同的，现在是要找有多少个独立的联动区间
///对于一个区间[l,r],join(l,r+1)这样对于一个新的区间如果是将原来的分开的联动的区间总体联动的就可以去掉
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int maxn=10000000;
int F[maxn];
ll pow_m(int b)
{
    ll a=26,ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int find(int x)
{
    if(F[x]==0) return x;//注意采用memset(0)的初始化的判别
    return F[x]=find(F[x]);
}
bool merge(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y)return false ;
    F[y]=x;return true;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int cnt=0; int L,R;
        memset(F,0,sizeof F);//注意这种初始化，maxn很大会卡题
        while(m--)
        {
            scanf("%d %d",&L,&R);
            if(merge(L,R+1))//做完大概觉得是水题，不过思想很重要，就是把一些区间搞起来，避免重复删减
                cnt++;
        }
        //#ifdef Local
        cout<<cnt<<" "<<n-cnt<<endl;
        //#endif // Local
        printf("%lld\n",pow_m(n-cnt));
    }
    return 0;
}
