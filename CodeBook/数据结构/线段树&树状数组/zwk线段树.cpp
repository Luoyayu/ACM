class SZSZ
{
private:
    int c[maxn];
    int lowbit(int val)
    {
        return val&-val;
    }
public:
    int init()
    {
        memset(c,0,sizeof c);
    }
    int add(int pos,int val)
    {
        pos++;
        for(int i=pos;i<=maxn;i+=lowbit(i))	c[i]+=val;
    }
    int sum(int pos)
    {
        int ans=0;
        for(int i=pos;i>0;i-=lowbit(i))	ans+=c[i];
        return ans;
    }
    int query(int l,int r)
    {
        return sum(r+1)-sum(l);
    }
}s[maxn];