///使用栈模拟
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 +  10;
stack<int>s;
int a[maxn],b[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        while(!s.empty())
            s.pop();
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        int sum=0;
        for(int i=1;i<=n;i++)
            if(!b[i])
            {
                while(s.size()&&s.top()<a[i])s.pop();
                if(s.empty())++sum;
            }
            else
                s.push(a[i]);
        printf("%d\n",sum+s.size());
    }
    return 0;
}
