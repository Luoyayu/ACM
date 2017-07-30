LCA(least common ancestors) 最近公共祖先
无向无环图(有根树)中LCA(T,u,v) 等于最短路(u,v)上经过的深度最小的点
1.离线并查集+tarjan算法 复杂度O(n+Q)

ST算法
int F[maxn],pos[maxn],tot;  
long long cost[maxn];  
  
int rmq[maxn];//rmq数组，就是欧拉序列对应的深度序列  
struct ST  
{  
    int mm[2*maxn];  
    int dp[2*maxn][20];//最小值对应的下标  
    void init(int n)  
    {  
        mm[0] = -1;  
        for(int i = 1; i <= n; i++)  
        {  
            mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];  
            dp[i][0] = i;  
        }  
        for(int j = 1; j <= mm[n]; j++)  
            for(int i = 1; i + (1<<j) - 1 <= n; i++)  
                dp[i][j] = rmq[dp[i][j-1]] < rmq[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];  
    }  
    int query(int a,int b)//查询[a,b]之间最小值的下标  
    {  
        if(a > b)swap(a,b);  
        int k = mm[b-a+1];  
        return rmq[dp[a][k]] <= rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];  
    }  
} st; 