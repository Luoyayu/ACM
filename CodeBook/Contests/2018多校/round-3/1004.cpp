#include <bits/stdc++.h>

using namespace std;
#define lowbit(x) x&(-x);
#define lc ((rt) << 1)
#define rc ((rt) << 1 | 1)
#define mid ((l + r) >> 1)
#define clr(a, b) memset(a,b,sizeof(a);
#define debug(a) cout << #a << " = " << a << endl;
#define push_back pb
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;

const int maxn = 1e6 + 7;

int euler_phi(int n) {           //欧拉函数 复杂度 O(√n)
    int m = (int)sqrt(n + 0.5);  //只用到√n筛质因子
    int ans = n;
    for (int i = 2; i <= m; i++)
        if (n % i == 0) {             //第一次找到必为质因子
            ans = ans / i * (i - 1);  //先除i防止中间溢出
            do
                n /= i;  //把该数的因子全部筛掉
            while (n % i == 0);
        }
    if (n > 1) ans = ans / n * (n - 1);  //防止还有一个质因子
    return ans;
}

///<*************欧拉表**************>
int phi[maxn];
int Euler[maxn] = {0};

void phi_table(int n) {  //筛法欧拉表
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        if (!phi[i])
            for (int j = i; j <= n; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
}

// 5 7 8 9 10 11 12 13 14
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w", stdout);
    //    phi_table(1000);
    //    for (int i = 1; i <= 500; i++) cout << i << " " << phi[i] << endl;
    int t;  // scanf("%d", &t);
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        if (n == 1)
            cout << 5 << endl;
        else
            cout << n + 5 << endl;
    }
}