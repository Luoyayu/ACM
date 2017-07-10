#include<bits/stdc++.h> 
using namespace std;
#define IOS std::ios::stdio(flase)
#define clr(x,num) memset(x,num,sizeof(x));
#define Debug(x) cout<<#x<<" = "<<x<<endl;
//#pragma comment(linker, "/STACK:102400000,102400000")//for C++
typedef long long ll;
const int maxn = 20000 + 7;
const int mod  = 1e9 + 7;
const int inf  = 0x3f3f3f3f;
const double esp = 1e-6;
const double pi = acos(-1);
int a[maxn];
//定义sequence(K)表示以下标为K的倍数组成的子序列[0,K,2K,...]
//query(K,S) 询问sequence(K)中第S大的数字
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        while(m--)
        {
            int K,S;scanf("%d%d",&K,&S);
            
        }

    }
}