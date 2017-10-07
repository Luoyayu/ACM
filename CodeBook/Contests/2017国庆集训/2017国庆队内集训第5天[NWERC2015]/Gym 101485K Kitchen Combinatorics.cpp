// 题意：给出 r种调料 , s种开胃菜, m种主菜, d种甜点以及n中三类菜不能两两搭配的对
//r<1000, s,m,d<=25
//下一行给出每种调料的不同品牌数
//下面r+s+m行给出每种菜所需的调味(规定三种菜如需要同一调味料品牌相同)
//下面n行给出不能搭配的对

//如果搭配总数大于 1e18 输出 too many

//25^3 模拟即可
//trick 比较 a*b > c 转换成 a> c/b

#include<bits/stdc++.h>
using namespace std;
#define clr(a,b) mesmet(a,b,sizeof(a));
typedef long long ll;
const ll MAX = 1e18;
vector<int> a[28],b[28],c[28];
bool ab[28][28], bc[28][28],ac[28][28];
int brand[2222];
void init()
{
    for(int i=0;i<28;i++)
    {
        a[i].clear();
        b[i].clear();
        c[i].clear();
    }
    clr(ab,0);clr(ac,0);clr(bc,0);
    clr(brand,0);

}
int main()
{
    int r,s,m,d,n;
    while(scanf("%d%d%d%d%d",&r,&s,&m,&d,&n)!=EOF)
    {
        init();
        for(int i=1;i<=r;i++) scanf("%d",&brand);

        for(int i=1;i<=s;i++)
        {
            int num,x;scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&x);
                a[i].push_back(x);
            }
        }

        for(int i=1;i<=m;i++)
        {
            int num,x;scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&x);
                b[i].push_back(x);
            }
        }

        for(int i=1;i<=d;i++)
        {
            int num,x;scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&x);
                c[i].push_back(x);
            }
        }

        for(int i=1;i<=n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);
            if(y<=s+m) ab[x][y-s]=1;
            else if(x<=s&&y>s+m) ac[x][y-s-m]=1;
            else if(x>s) bc[x-s][y-s-m]=1; 
        }

        ll ans = 0;
        for(int i=1;i<=s;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<=d;k++)
                {
                    if(ab[i][j]||ac[i][k]||bc[j][k]) continue;

                    set<int> ss;
                    for(int p=0;p<a[i].size();p++)
                        ss.insert(a[i][p]);
                    
                    for(int p=0;p<b[j].size();p++)
                        ss.insert(b[j][p]);

                    for(int p=0;p<c[k].size();p++)
                        ss.insert(c[k][p]);

                    ll cnt = 1;
                    for(auto it=ss.begin();it!=ss.end();it++)
                    {
                        if(1.0*brand[*it]>1.0>MAX/cnt) return !printf("too many");//直接判断cnt*=brand[*it] 容易爆此处应该转为除非比较大小
                        else cnt = cnt * (long long)brand[*it]l
                    }
                    if(ans+cnt>MAX||ans+cnt<0) return !printf("too many");
                    ans += cnt;
                }

        printf("lld\n",ans);
    }
    return 0;
}