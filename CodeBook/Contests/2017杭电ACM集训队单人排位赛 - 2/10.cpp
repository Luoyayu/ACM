#include<bits/stdc++.h>
#define Debug(x) cout<<#x<<"= "<<x<<endl;
using namespace std;
const int maxn=1e6+7;
void solve();
int S,T;
int main()
{
    int a,n;
    while(scanf("%d%d%d",&n,&S,&T)!=EOF)
    {
        int con[10]={0},ans=abs(S-T);
        while(n--)
            scanf("%d",&a),con[a]=1;

        for(int i=0;i<=500000;i++)//b_f
        {
            int tmp=i,flag=1,cnt=0;
            while(tmp&&flag)
            {
                if(con[tmp%10]) flag=0;
                cnt++,tmp/=10;
            }
            if(i==0&&con[0]==0) cnt++;//如果是可以按倒0,cnt++!!
            if(flag)
                ans=min(ans,abs(i-T)+cnt);

        }
        printf("%d\n",ans);
    }
    return 0;
}

