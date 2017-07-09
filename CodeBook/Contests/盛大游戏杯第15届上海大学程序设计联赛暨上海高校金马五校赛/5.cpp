#include <bits/stdc++.h>
#define rep(i,s,t) for (int i=s;i<t;++i)
using namespace std;
typedef long long ll;
int a[20];
int main()
{
    string s;
    int num;
    while (cin>>s>>num)
    {
        ll ans=0;
        int now=0;
        int l=s.size();
        rep(i,0,l) a[i]=s[i]-'a';
        rep(i,0,l) ans+=a[i]*pow(26,l-i-1);

        if(ans == 0)
        {
            printf("0\n");
            continue;
        }
        while (ans)
        {
            a[now++]=ans%num;
            ans /= num;
        }
        for (int i=now-1;i>=0;--i)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
