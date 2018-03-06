//题意：马尔科夫链的天气模型
//读懂题意的话就是水题 注意输入
#include<bits/stdc++.h>
using namespace std;
double mp[5][5];
void solve1()
{
    char c;int last,cur;
    scanf("%d",&last);
    double ans=1;
    while(c=getchar()!='\n')
    {
        scanf("%d",&cur);
        ans *= mp[last][cur];
        last=cur;
    }
    printf("%.8f\n",ans);
}
void solve2()
{
    int x;scanf("%d",&x);
    double j = mp[x][x];
    double ans = 1;
    while(j>1e-9)
    {
        ans += j;
        j*=mp[x][x];
    }
    printf("%.8f\n",ans);
}
int main()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            scanf("%lf",&mp[i][j]);

    solve1();solve1();
    solve2();solve2();

    //getchar();getchar();
    return 0;
}

