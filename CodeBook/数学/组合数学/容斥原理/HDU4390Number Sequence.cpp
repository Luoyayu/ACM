#include <bits/stdc++.h>
//题意:给出b[b1,bn]序列计算有多少a[a1,an]满足|-|ai == |-|bi  (ai>1)
//由质因子分解的唯一性得,等式两边有相同的且数量也相同的质因子;
//那么通过将b数组得质因子全部发掘出来通过组合形成a数目为n得新序列
//答案就是将这些质因子分配进n个位置=>组合数学问题
//设在b序列种有x个不同的质因子,每个出现次数mi次
//把mi个相同的球放进n给盒子的方案数为C(n-1, m+n-1) [允许有空位置]
//那么最终答案就是|-|(i~x) [C(n-1,mi+n-1)];
//当然这是允许为空的存在，实际上我们规定了ai>1，把mi个相同的球的个数不一定全大于n
//所以要采用容斥的思想减去那些有空格的情况；
//因为至少有一个为空与至少有两个为空的情况存在重复(选两个为空但是放小球也是在n-2个盒子里放指不定最后没空或者一个空)
//所以ans =|-|(1~x) [C(n-1,m+n-1)]
// - {C(1,n) |-|(1~x)[C(n-2,mi+n-2)]- + — +```}
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL c[505][505];
vector<int> v;
void getPrime_factor(int num)  //分解质因子含重复情况
{
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            num /= i;
            v.push_back(i);  //循环外不重复
        }
    }
    if (num > 1) v.push_back(num);
}
void init()  //预处理C(i,j) i下j上
{
    for (int i = 0; i <= 500; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
}
inline LL getRaw(int n, int m)  //返回C(m+n-1,n-1)
{
    return c[m + n - 1][n - 1];
}
LL slove(int n) {
    int a[1005] = {1}, cnt = 0;  // a数组存第几种质因子的个数
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[i - 1])
            a[++cnt] = 1;
        else
            a[cnt]++;
    }
    LL ans = 1;
    for (int i = 0; i <= cnt; i++) ans = (ans * getRaw(n, a[i])) % MOD;
    // cout<<ans<<endl; 未减空格的raw
    for (int i = 1; i < n; i++) {
        LL tmp = c[n][i];
        for (int j = 0; j <= cnt; j++) {
            tmp = (tmp * getRaw(n - i, a[j])) % MOD;
        }
        if (i & 1)
            ans = ((ans - tmp) + MOD) % MOD;  // ans - (奇正偶符)
        else
            ans = (ans + tmp) % MOD;
    }
    return ans;
}
int main() {
    init();
    while (scanf("%d", &n) != EOF) {
        v.clear();  //日常气清空
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            getPrime_factor(k);
        }
        printf("%I64d\n", slove(n));
    }
    return 0;
}