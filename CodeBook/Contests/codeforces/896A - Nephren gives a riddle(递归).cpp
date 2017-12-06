#include <bits/stdtr1c++.h>
using namespace std;
const int maxn = (int)1e5+7;
typedef long long ll;
ll len[maxn];
string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string f1 = "What are you doing while sending \"";
string f2 = "\"? Are you busy? Will you send \"";
string f3 = "\"?";
ll len1 = f1.length(), len2 = f2.length(), len3 = f3.length(), lens = s.length();
void init() {
    for(int i=0;i<maxn;i++)
        len[i] = (ll)4e18; // 初始化为无穷大
    len[0] = lens;
    for (int i = 1; i <= maxn; i++) {
        len[i] = (len[i - 1] << 1) + len1 + len2 + len3;
        if (len[i] >= 1e18) break;
    }
}
char fun(ll n, ll k)
{
    if(!n) return s[k-1];
    if(k<=len1) return f1[k-1]; 
    k -= len1;
    if(k<=len[n-1]) return fun(n-1,k); 
    k -= len[n-1];
    if(k<=len2) return f2[k-1];
    k -= len2;
    if(k<=len[n-1]) return fun(n-1, k); 
    k-= len[n-1];
    return f3[k-1];
}

int main() {
    init();
    int q;scanf("%d", &q);
    while (q--) {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        ll fn = len[n];
        if (k > fn) cout<<'.';
        else cout<<fun(n, k);
    }
}