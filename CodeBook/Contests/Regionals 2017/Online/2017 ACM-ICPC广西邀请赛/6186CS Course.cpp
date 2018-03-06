#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn];
int cnt[maxn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main ()
{
    int n,p;
    while (scanf("%d %d",&n,&p)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        int ans3=0;int MAX=0;
        for (int i=0;i<n;i++)
        {
            a[i] =read();
            ans3^=a[i];
            int tmp=a[i], len=0;
            while(tmp)
            {
                if(tmp%2) cnt[len]++;
                tmp>>=1;len++;
                if (MAX<len) MAX=len;
            }
        }
        for (int i=0;i<MAX;i++) 
                cnt[i]=n-cnt[i];
        for (int i=0;i<p;i++)
        {
            int temp = read();
            int t=a[temp-1];
            int ans1=0,ans2=0;
            for (int j=0;j<MAX;j++)
            {
                if (cnt[j]==0||(cnt[j]==1&&t%2==0)) ans1+=1<<j,ans2+=1<<j;
                else if ((cnt[j]==n-1&&t%2==0&&n!=2)|| (cnt[j]==1&&t%2!=0&&n!=2)|| (cnt[j]>1&&cnt[j]<n-1))
                    ans2+=1<<j;
                t>>=1;
            }
            printf ("%d %d %d\n",ans1,ans2,ans3^a[temp-1]);
        }
    }
    return 0;
}