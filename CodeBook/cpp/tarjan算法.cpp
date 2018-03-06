//tarjan�㷨
#include<stdio.h>
#include<string.h>  
#include<vector>  
#include<algorithm>  
using namespace std;  
#define maxn 10005  
vector<int>mp[maxn];  
int ans[maxn],is[maxn],dfn[maxn],low[maxn],vis[maxn]; //DFNʱ������ýڵ㱻�������Ĵ��� 
//LOW[i] i��i���ڵ������ܹ�׷�ݵ��������ջ�нڵ�Ĵ����
//��DFN[i]==LOW[i] ʱ��iΪ�������Թ���һ��ǿ��ͨ���� 
int n,m;
int tt,cnt,sig;  
void init()  
{  
    memset(low,0,sizeof(low));  
    memset(dfn,0,sizeof(dfn));  
    memset(vis,0,sizeof(vis));  
    for(int i=1;i<=n;i++)
		mp[i].clear();  
}  
void Tarjan(int u)  
{  
    vis[u]=1;  
    low[u]=dfn[u]=cnt++;  
    for(int i=0;i<mp[u].size();i++)  
    {  
        int v=mp[u][i];  
        if(vis[v]==0)
			Tarjan(v);  
        if(vis[v]==1)
			low[u]=min(low[u],low[v]);  
    }  
    if(dfn[u]==low[u])
        sig++; 
}  
void Slove()  
{  
    int tt=-1;cnt=1;sig=0;  
    for(int i=1;i<=n;i++)  
        if(vis[i]==0)   
            Tarjan(i); 
	if(sig==1) 
		printf("Yes\n") ;
	else 
		printf("No\n");
   // printf("%d\n",sig);  
}  
int main()  
{  
    while(~scanf("%d",&n),n)  
    {   
        scanf("%d",&m);  
        init();  
        for(int i=0;i<m;i++)  
        {  
            int x,y;  
            scanf("%d%d",&x,&y);  
            mp[x].push_back(y);  
        }  
        Slove();  
    }
    return 0;
}  
