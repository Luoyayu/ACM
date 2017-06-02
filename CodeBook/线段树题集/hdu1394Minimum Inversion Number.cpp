#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
/*
//��С��ת����������ai,aj(i<j&&ai<aj)�Ķ���
//����������һ�����У����԰ѵ�n��������Ҫ�Ƶ�����ĩβ
//������С��ת��ֵ
//�����߶�����������
#define Ls node<<1
#define Rs node<<1|1
#define lson Ls,l,M
#define rson Rs,M+1,r
int s[maxn<<2];
int tree[maxn<<2];
void maintain(int node)
{
    tree[node]=tree[Ls]+tree[Rs];
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node] = 0;
        return;
    }
    int M=(l+r)>>1;
    build(lson),build(rson),maintain(node);
}
void update(int pos,int node,int l,int r)
{
    if(l==r)
    {
        tree[node] = 1;
        return;
    }
    int M=(l+r)>>1;
    if(pos<=M) update(pos,lson);
    else update(pos,rson);
    maintain(node);
}
int query(int ql,int qr,int node,int l,int r)
{
    if(ql<=l&&qr>=r)
        return tree[node];
    int M=(l+r)>>1;
    int ans=0;
    if(ql<=M) ans+=query(ql,qr,lson);
    if(qr>r) ans+=query(ql,qr,rson);
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        build(1,1,n);
        int sum=0;

        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            sum+=query(s[i]+1,n,1,1,n);
            update(s[i]+1,1,1,n);
        }

        int MIN=sum;
        for(int i=0;i<n;i++)
        {
            sum=sum-2*s[i]+n-1;
            MIN=min(MIN,sum);
        }
        printf("%d\n",MIN);
    }
    return 0;
}*/
//���������⣬�������ԭʼ��������������ÿ�β������ǽ���ǰ���еĵ�һ�����õ����һ��λ�ã�
//���Դ𰸾͸���Ϊans-���б���С�����ֵĸ���+���б���������ֵĸ���
typedef long long ll;
int n,m,bit[maxn],a[maxn];
#define lowbit(x) (x)&(-x)
int sum(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}
void add(int x, int d)
{
    while(x <= n)
    {
        bit[x] += d;
        x +=lowbit(x);
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(bit, 0, sizeof(bit));
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]++;
            ans += sum(n) - sum(a[i]);//��������
            #ifdef Local
            printf("%d: %d %d %d \n",i,sum(n),sum(a[i]),ans);
            #endif // Local
            add(a[i], 1);
        }

        int cur = ans;
        for(int i=1;i<n;i++)
        {
            cur+= (n - a[i]) - (a[i]-1);
            ans = min(ans, cur);
        }
        printf("%d\n",ans);
    }
    return 0;
}

