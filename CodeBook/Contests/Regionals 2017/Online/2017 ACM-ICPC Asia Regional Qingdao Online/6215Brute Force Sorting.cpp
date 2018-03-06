#include <bits/stdc++.h>
using namespace std;
//题意:删除序列中所有的逆序对
//链表模拟即可
const int maxn = 1e6 +7;
int sq[maxn],pre[maxn],nxt[maxn];
bool del[maxn];
set<int> st;//待删元素的序号
vector<int> tmp;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(del, false, sizeof(del));
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)  scanf("%d", &sq[i]), pre[i]=i-1, nxt[i]=i+1, st.insert(i);
        nxt[0] = 1, pre[n+1] = n, pre[1] = 0, nxt[n] = n+1;
        sq[0] = 0, sq[n+1] = maxn;

        while(st.size())
        {
            //Pre x Next
            tmp.clear();
            for(auto &x:st)
            {
                int Next = nxt[x], Pre = pre[x];//取待删元素的前一个和后一个序号
                if(sq[Pre] > sq[x]) //如果前一个大于当前的 满足降序
                    tmp.push_back(Pre),tmp.push_back(x);//就把前一个和当前的序号塞入数组
                if(sq[x]>sq[Next])
                    tmp.push_back(x),tmp.push_back(Next);
            }
            st.clear();
            for(auto &x:tmp)//分析待删除元素的序号
            {
                if(!del[x])
                {
                    int Next = nxt[x], Pre = pre[x];
                    nxt[Pre] = Next;pre[Next] = Pre;
                    st.insert(Pre);
                    del[x] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i=nxt[0];i!=n+1;i=nxt[i]) cnt++;
        printf("%d\n",cnt);
        for(int i=nxt[0];i!=n+1;i=nxt[i]) printf("%d ",sq[i]);
        printf("\n");
    }
    return 0;
}