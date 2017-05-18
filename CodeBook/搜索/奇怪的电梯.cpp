#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,k[202],vis[202];
int bfs(int a,int b)
{
    queue<int> Q;
    Q.push(a);
    vis[a]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(u+k[u]>0&&u+k[u]<=n&&!vis[u+k[u]])
            Q.push(u+k[u]),vis[u+k[u]]=vis[u]+1;
        if(u-k[u]>0&&u-k[u]<=n&&!vis[u-k[u]])
			Q.push(u-k[u]),vis[u-k[u]]=vis[u]+1;
        if(u==b) 
			return vis[u]-vis[a];
    }
    return -1;
}
int main()
{
    int a,b;
    while(cin>>n&&n)
    {
        memset(vis,0,sizeof(vis));
        cin>>a>>b;
        for(int i=1; i<=n; i++)//从1层开始算起 
            cin>>k[i];
        cout<<bfs(a,b)<<endl;
    }
    return 0;
}