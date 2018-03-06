///贪心
#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=1000+10;
using namespace std;
int vis[maxn];
struct node
{
    int l,r,num;
}Q[maxn];

bool cmp(node& a,node& b)
{
    return a.r<b.r;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        int n,m,k;
        memset(vis,0, sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        while(k--)
        {
            int tmp;
            scanf("%d",&tmp);
            vis[tmp]=1;
        }
        for (int i = 0; i < m ; ++i)
            scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].num);

        sort(Q,Q+m,cmp);
        int flag=1, cnt=0;//统计至少安装的灯数
        for(int i=0;i<m;i++)
        {
            int totQ=0;//统计每个区间
            int RR = Q[i].r,LL = Q[i].l;
            for(int KK=LL;KK<=RR;KK++)
                if(vis[KK])
                    totQ++;

            if(totQ>=Q[i].num)//pass
                continue;

            while(totQ<Q[i].num && RR>=LL) //缩减区间
            {
                if (vis[RR]==0)
                {vis[RR] = 1; totQ++;cnt++;}
                RR--;
            }

            if(totQ<Q[i].num)
            {
                flag=0;
                break;
            }
        }
        if(!flag)
            printf("Case %d: -1\n",kase);
        else
            printf("Case %d: %d\n",kase,cnt);
    }
    return 0;

}
