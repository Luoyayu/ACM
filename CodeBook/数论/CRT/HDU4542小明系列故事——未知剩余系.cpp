#include <iostream>
#include <cstdio>
using namespace std;
int n;
const int maxn=50000;
typedef unsigned long long LL;
LL ans,ip[maxn];
const LL INF=((LL)1<<62)+1;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
void prim()
{
    for(int i=1;i<=maxn;i++)
        ip[i]=i;
    for(int i=1;i<=maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
            ip[j]--;
        if(!ip[ip[i]]) ip[ip[i]]=i;
        ip[i]=0;
    }
}
void dfs(int num,LL tmp,int dept)
{
    if(num==n) ans=min(tmp,ans);
    if(num>=n || (dept>=16)) return ;
    for(int i=1; i<=63; i++)
    {
        if(tmp>ans/prime[dept]) break;
            dfs(num*(i+1), tmp*=prime[dept], dept+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;scanf("%d",&t);
    prim();
    for(int kase=1;kase<=t;kase++)
    {
        int type;
        cin>>type>>n;
        if(type)
            ans=ip[n];
        else
        {
            ans = INF;
            dfs(1,1,0);
        }
        printf("Case %d: ",kase);
        if(ans==0)
            cout<<"Illegal"<<endl;
        if(ans>=INF)
            cout<<"INF"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
