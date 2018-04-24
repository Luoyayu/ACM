#include<bits/stdc++.h>
using namespace std;
// 选定区间异或最大值并且输出字典序最小的区间端点值
typedef long long ll;
const int INF=0x3f3f3f3f;
int n, num, ans, l, r, cnt;
int ch[1000003*32][2];
int idx[1000003*32]; //记录字典序
inline int read() {
    int x=0, f=1;
    auto ch= static_cast<char>(getchar());
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch= static_cast<char>(getchar());}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch= static_cast<char>(getchar());}
    return x*f;
}
void init() {
    num = 0; cnt = 1; ans = l = r = 0;
    memset(idx, INF, sizeof(idx));
}

void Insert(int id, int x) {
    int k = 0;
    for (int i = 31; i >= 0; i--) {
        int d = (x >> i) & 1; //取出二进制第i位
        if (!ch[k][d]) {
            memset(ch[cnt], 0, sizeof(ch[cnt]));
            ch[k][d] = cnt++; // 产生新节点并记录
        }
        k = ch[k][d];
    }
    idx[k] = min(idx[k], id); // 保证同一个异或和的字典序最小。每一个k值代表一个异或和
}
void query(int id, int x) {
    int k = 0, res = 0;
    for(int i=31; i>=0; i--) {
        int d = (x>>i) & 1; // 贪心策略，从高位开始，让高位尽可能的为1，那么这个数位如果是1，那么就找0（1^1），如果是0，那么就找1（0^1）；
        if(ch[k][d^1]){k=ch[k][d^1];res+=(1<<i);} // 存在与d相异的转移k,更新答案
        else{k=ch[k][d];res+=(0<<i);} // 如果并没有，那么往下贪心，这一位不变
    }
    if(res>ans){ans=res;l=idx[k];r=id;}
    else if(res == ans) {
        if(idx[k]<l){l=idx[k];r=id;}
        else if(idx[k]==l && id<r){r=id;}
    }
}
int main() {
    int t = read();
    for(int ca=1;ca<=t;ca++) {
        n = read();
        init(); Insert(0, 0);
        for(int i=1; i<=n; i++) {
            num ^= read(); // 前缀异或
            Insert(i, num);
            query(i, num);
        }
        printf("%d %d %d\n", ans, l+1, r);
    }
}