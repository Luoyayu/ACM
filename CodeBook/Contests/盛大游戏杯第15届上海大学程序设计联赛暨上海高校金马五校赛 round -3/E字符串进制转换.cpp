#include <bits/stdc++.h>
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
        int l=s.size();
        for(int i=0;i<l;i++)
            a[i]=s[i]-'a';

        for(int i=0;i<l;i++)
            ans+=a[i] * pow(26,l-i-1);
        if(ans == 0)
        {
            printf("0\n");
            continue;
        }
        int cnt =0;
        while(ans)
        {
            a[cnt++]=ans%num;
            ans /= num;
        }
        for (int i=cnt-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
