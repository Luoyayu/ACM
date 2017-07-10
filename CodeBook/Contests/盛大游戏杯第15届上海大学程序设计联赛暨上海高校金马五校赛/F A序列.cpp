#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ld[500010],rd[500010];
int s[500010];
int a[500010];
int n;
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int cnt = 1;
        ld[1] = 1;
        rd[n] = 1;
        s[cnt] = a[1];
        for(int i = 2; i <= n; i++)
        {
            if(a[i] > s[cnt])
            {
                s[++cnt] = a[i];
                ld[i] = cnt;
            }
            else
            {
                int k = lower_bound(s+1, s + cnt + 1, a[i]) - s;
                ld[i] = k;
                s[k] = a[i];
            }
        }
        cnt = 1;
        s[cnt] = a[n];
        for(int i = n - 1; i >= 1; i--)
        {
            if(a[i] > s[cnt])
            {
                s[++cnt] = a[i];
                rd[i] = cnt;
            }
            else
            {
                int k = lower_bound(s+1, s + cnt +1, a[i]) - s;
                rd[i] = k;
                s[k] = a[i];
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans =max(ans, min(2*ld[i]-1 , 2*rd[i]-1));
        }
        cout<<ans<<"\n";
    }
    return 0;
}