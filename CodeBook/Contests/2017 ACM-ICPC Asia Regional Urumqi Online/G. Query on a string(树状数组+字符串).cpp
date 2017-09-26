//题意:给出字符串S(1e5),T(10);Q(1e5) 次操作
//C a b 改变第a个字符为b
//Q a b 查询S[a,b]中出现T的次数
//思路：树状数组
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int c[maxn];
char s[maxn], p[maxn];
int lens, lenp;
bool vis[maxn];
#define lowbit(x) x & -x;
void add(int pos, int value)
{
    while(pos<lens)
    {
        c[pos] += value;
        pos += lowbit(pos);
    }
}
int sum(int pos)
{
    int ret = 0;
    while(pos>0)
    {
        ret += c[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int q;scanf("%d",&q);
        memset(vis,0,sizeof(vis));
        memset(c,0,sizeof(c));
        scanf("%s %s",s+1, p+1);
        lenp = strlen(p+1);lens = strlen(s+1);
        for(int i=1;i+lenp-1<=lens;i++)
        {
            bool flag = 1;
            for(int j=1;j<=lenp;j++)
                if(s[i+j-1]!=p[j])
                {
                    flag = 0;
                    break;
                }

            if(flag)
            {
                add(i,1);vis[i]=1;
            }
        }
        while(q--)
        {
            char ch;scanf(" %c",&ch);
            if(ch=='Q')
            {
                int l,r;scanf("%d %d",&l,&r);
                r -= lenp;r++;
                if(l<=r) printf("%d\n",sum(r) - sum(l-1));
                else printf("0\n");
            }
            else
            {
                int pos;scanf("%d %c",&pos,&ch);
                s[pos] = ch;
                for(int i=max(1,pos-lenp+1);i<=min(pos,lens-lenp+1);i++)
                {
                    bool flag = 1;
                    for(int j = 1;j<=lenp;j++)
                    {
                        if(s[i+j-1]!=p[j])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag != vis[i])
                    {
                        if(vis[i]) add(i,-1);
                        else add(i,1);
                        vis[i] = !vis[i];
                    }
                }
            }
        }
    }
    return 0;
}

/*
1
5
AABBABA
AA
Q 1 3
C 6 A
Q 2 7
C 2 B
Q 1 5

 */