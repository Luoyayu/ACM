//Games
#include<bits/stdc++.h>
#define Debug(x) cout<<#x<<"= "<<x<<endl;
using namespace std;
const int maxn=25;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,a,b;
        scanf("%d%d%d%d",&n,&m,&a,&b);
        int g[maxn][maxn]={0};
        int aa,bb;
        while(m--)
            scanf("%d%d",&aa,&bb),g[aa][bb]=g[bb][aa]=1;
        if(g[a][b])
            printf("chhappy\n");
        else printf("chsad\n");
    }
    return 0;
}

