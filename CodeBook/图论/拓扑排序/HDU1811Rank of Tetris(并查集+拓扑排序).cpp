//编号大的优先级高
//正确 OK               ****** （1）
//冲突 CONFLICT         ****** （2）  成环 或且信息不全面
//信息不全面 UNCERTAIN  *****  （3） 存在多个indegree=0的点，既拓扑序不唯一
//RP相同的用并查集合并元素缩点
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
const int maxn = 10000 + 55;
using namespace std;
int N, M, sum;
vector<int> map[maxn];
int indeg[maxn], father[maxn], Rank[maxn];
struct node
{
    int from, to;
    char op;
} edge[maxn];

int find(int x)
{
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
bool merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return 0;
    else
    {
        /*瞎优化*1
        if(Rank[fx]>=Rank[fy])
            father[fy]=fx,Rank[fx]+=Rank[fy];
        else
            father[fx]=fy,Rank[fy]+=Rank[fx];
        */
        father[fy] = fx;
        return 1;
    }
}
inline void init()
{
    sum = 0;
    for (int i = 0; i < N; i++)
        father[i] = i, indeg[i] = 0, Rank[i] = 1, map[i].clear();
}
void toposort()
{
    queue<int> q;
    int flag = 0;
    for (int i = 0; i < N; i++)
        if (indeg[i] == 0 && father[i] == i)
            q.push(i);
    //printf("%d\n",q.size());// 瞎写*2
    while (!q.empty())
    {
        if (q.size() > 1) //存在多个入度为0的节点，他们之间的信息就不确定
        {
            flag = 1;
            //break;
        }
        int pos = q.front();
        q.pop();
        sum++;
        for (int i = 0; i < map[pos].size(); i++)
        {
            int v = map[pos][i];
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    if (sum != N)
        printf("CONFLICT\n"); //排序的总个数不等于点数，存在回路！
    else if (flag)
        printf("UNCERTAIN\n");
    else
        printf("OK\n");
}

int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
        init();
        for (int i = 0; i < M; i++)
        {
            scanf("%d %c %d", &edge[i].from, &edge[i].op, &edge[i].to);
            if (edge[i].op == '=')
                if (merge(edge[i].from, edge[i].to)) //合并也是一种排序
                    sum++;
        }
        for (int i = 0; i < M; i++)
        {
            if (edge[i].op == '=')
                continue;
            int x = find(edge[i].from);
            int y = find(edge[i].to);

            if (edge[i].op == '>')
                map[x].push_back(y), indeg[y]++;
            else
                map[y].push_back(x), indeg[x]++;
        }
        toposort();
    }
    return 0;
}
