//稳定婚姻问题和Gale-Shapley算法 延迟认可算法
//带权二分图 求稳定匹配
#include<bits/stdc++.h>
#define next NEXT
#define stack STACK
#define rank RANK
using namespace std;
const int maxn=555;
const int manm=555;
const int INF=0x3f3f3f3f;
int n,m;
int liboy[maxn][maxn],ligirl[maxn][maxn];
int boy[maxn],girl[maxn];
int rank[maxn];
map<string,int> map_boy,map_girl;
string sboy[maxn],sgirl[maxn];
void gale_shapley()
{
    memset(boy,0,sizeof boy);
    memset(girl,0,sizeof girl);
    for(int i=1;i<=n;i++)
        rank[i]=1;
    while(1)
    {
        int flag=0;
        for(int i=1;i<=n;i++)
            if(!boy[i])
            {
                int g=liboy[i][rank[i]++];
                if(!girl[g])
                    boy[i]=g,girl[g]=i;
                else if(ligirl[g][i]>ligirl[g][girl[g]])
                    boy[girl[g]]=0,girl[g]=i,boy[i]=g;
                flag=1;
            }
        if(!flag) break;
    }
    for(int i=1;i<=n;i++)
        cout<<sboy[i]<<' '<<sgirl[boy[i]]<<endl;
    printf("\n");
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(scanf("%d",&n)!=EOF)
    {
        char s[maxn];
        getchar();
        map_boy.clear();map_girl.clear();
        int pos=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            sboy[i]=s,map_boy[s]=i;
            for(int j=1;j<=n;j++)
            {
                scanf("%s",s);
                int tmp=map_girl[s];
                if(!tmp)
                    map_girl[s]=tmp=pos++;
                sgirl[tmp]=s;
                liboy[i][j]=tmp;
            }
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            int x=map_girl[s];
            for(int j=0;j<n;j++)
            {
                scanf("%s",s);
                int y =map_boy[s];
                ligirl[x][y]=n-j;
            }
        }
        gale_shapley();
    }
    return 0;
}
