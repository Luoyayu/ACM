//1000000
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn= 1000000+100;
const int inf = 0x3fffffff;
typedef long long ll;
int a[maxn];
void pre()
{
    int cnt=1;
    for(int i=1;i<=maxn;i++)
    {
        if(i%2==0||i%3==0||i%5==0)
            a[i] = cnt++;
        else
            a[i]=a[i-1];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    memset(a,0,sizeof a);
    pre();
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
