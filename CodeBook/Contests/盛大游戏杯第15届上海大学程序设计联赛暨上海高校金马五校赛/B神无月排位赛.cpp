#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
const int maxc = 1e3 + 5;
int a[510];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int id=1,ans = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]) ans += 10;

            else if(!a[i]&& ans>0)
                ans -= 5;

            if(ans>=100)
            {
                if(a[i+1] && a[i+2])
                    id++,ans=0,i+=2;
                else if(a[i+1]+a[i+2]+a[i+3]>=2&&(a[i+1]+a[i+2]))
                    id++, ans =0,i+=3;
                else if(a[i+1]==0&&a[i+2]==0)
                    ans = 60,i += 2;
                else
                    ans = 60, i+=3;
            }
        }
        if(id==1)
            printf("D\n");
        else if(id==2)
            printf("C\n");
        else if(id==3)
            printf("B\n");
        else if(id==4)
            printf("A\n");
        else printf("S\n");
    }
    return 0;
}









