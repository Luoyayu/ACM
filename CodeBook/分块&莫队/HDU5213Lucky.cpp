#include<bits/stdc++.h> //for G++
using namespace std;
#define y2 Y2
#define next Next;
#define lowbit(x) x&(-x)
#define IOS std::ios::stdio(flase)
#define clr(x,num) memset(x,num,sizeof(x));
#define Debug(x) cout<<#x<<" = "<<x<<endl;
//#pragma comment(linker, "/STACK:102400000,102400000")//for C++
/* for G++
int size = 256 << 20; // 256MB  
char *p = (char*)malloc(size) + size;  
__asm__("movl %0, %%esp\n" :: "r"(p));
*/
typedef long long ll;
typedef __int64 LL;
const int maxn = 3e4 + 7;
const int maxc = 1e3 + 5;
const int maxr = 1e5 + 5;
const int MOD  = 1e9 + 7;
const int inf  = 0x3f3f3f3f;
const double esp = 1e-6;
const double pi = acos(-1);
int n,k,m,l,r,u,v;
int a[maxn];
//题意:K(odd)=a∈{a1,a2...an}*(X∈[l,r]*Y∈[u,v]),找出(X,Y)对数
//思想:莫队算法分块+容斥定理
int solve()
{

}
int mian()
{
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%d",&l,&r,&u,&v);
            printf("%d\n",solve());
        }
    }
    return 0;
}