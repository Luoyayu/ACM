#include <bits/stdc++.h>
//好题图的两种存储方式都上,灵活优化复杂度
using namespace std;
const int maxn = 2017;
int n;
int map1[maxn][maxn],map2[maxn][maxn];
vector<int> G1[maxn];
vector<int> G2[maxn];
char ch[maxn][maxn];
bool dfs(int MAP[][maxn],vector<int>G[maxn])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            for(int k=0;k<G[G[i][j]].size();k++)
                if(MAP[i][G[G[i][j]][k]]==0)
                    return 0;
        }
    }
    return 1;
}

int main()
{
    int t;while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            memset(map1,0, sizeof(map1));
            memset(map2,0, sizeof(map2));
            for(int i=0;i<maxn;i++)
                G1[i].clear(),G2[i].clear();
            scanf("%d",&n);
            for(int i=0;i<n;i++)
                scanf("%s",ch[i]);

            for(int i=0;i<n;i++) {
                for (int j = 0; j < n; j++) {

                    if (ch[i][j] == 'P')
                        map1[i][j] = 1, G1[i].push_back(j);
                    else if (ch[i][j] == 'Q')
                        map2[i][j] = 1, G2[i].push_back(j);

                }
            }
            if(dfs(map1,G1)&&dfs(map2,G2))
                printf("T\n");
            else
                printf("N\n");

        }
    }
    return 0;
}

