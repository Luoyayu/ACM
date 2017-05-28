
//1000000 质因子的乘积%471115667135
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 471115667135;
const int maxn=100005;
ll ans[]={};
vector<int> prime_factor[maxn];
void init()
{
    for(int i=2;i<maxn;i++)
        for(int j=i;j<maxn;j+=i)
            prime_factor[j].push_back(i);
}
int main()
{
    int n;
    init();
    //freopen("C:\\Users\\gavin\\Desktop\\input.txt","w",stdout);
    //for(int n=1;n<=1000000;n++)
    while(scanf("%d",&n)!=EOF)
    {
        ll ans=1;
        int size=prime_factor[n].size();
        #ifdef Loc
        cout<<size<<endl;
        for(int i=0;i<size;i++)
            cout<<prime_factor[n][i]<<" ";
        cout<<endl;
        #endif // Local
        for(int i=0;i<size;i++)
            ans=(ans%mod)*(prime_factor[n][i]%mod)%mod;
        //printf("%lld,",ans);
        printf("%lld\n",ans);
    }
    return 0;
}
