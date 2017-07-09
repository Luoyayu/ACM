#include<bits/stdc++.h>
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
const int maxc = 1e3 + 5;
const int maxr = 1e5 + 5;
const int MOD  = 1e9 + 7;
const int inf  = 0x3f3f3f3f;
const double esp = 1e-6;
const double pi = acos(-1);
const int maxn = 1e8-222;
int phi[maxn];
int Euler[maxn]={0};
void phi_table(int n)//筛法欧拉表
{
    phi[1]=1;
    for(int i=2;i<=n;i++) if(!phi[i])
        for(int j=i;j<=n;j+=i)
        {
            if(!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}
int main()
{
    phi_table(maxn);
    cout<<"OK\n";
}
