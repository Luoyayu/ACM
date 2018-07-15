#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//题意：给出字符串组s1~sn(n<=24),
//问如何尽可能的选字符串使得每个字符出现的次数均为偶数
//思路：二进制维护集合,暴力O(2^n),中间相遇法降复杂度O(2^{n/2}log(n))，折半处理
//考虑到每个字符只有出现的奇偶次影响结果,故可以使用二进制保存出现次数的状态,这样每个字符串就对应了一个位向量A
const int maxn = 24;
const int inf = 0x3f3f3f3f;
const ll infLL = 1LL << 62;
char s[1005];
int A[maxn];
map<int, int> table;
int bitCount(int x) {
    return !x ? 0 : bitCount(x >> 1) + (x & 1);
}  //返回集合大小
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            A[i] = 0;
            for (int j = 0; s[j]; j++)
                A[i] ^= (1 << (s[j] - 'A'));  // xor count奇偶
        }
        table.clear();  // table[x]保存的是xor值为x，bitCount尽量大的子集
        int n1 = n >> 1, n2 = n - n1;         //先处理前半部分
        for (int i = 0; i <= (1 << n1); i++)  //枚举前2^n1中取值
        {
            int x = 0;
            for (int j = 0; j < n1; j++)
                if (i & (1 << j)) x ^= A[j];
            if (!table.count(x) || bitCount(table[x]) < bitCount(i))
                table[x] = i;
        }

        int ans = 0;
        for (int i = 0; i < n2; i++) {
            int x = 0;
            for (int j = 0; j < n2; j++) {
                if (i & (1 << j)) x ^= A[n1 + j];
                if (table.count(x) &&
                    bitCount(x) < bitCount(table[x]) + bitCount(i))
                    ans = (i << n1) ^ table[x];
            }
        }
        printf("%d\n", bitCount(ans));
        for (int i = 0; i < n; i++)
            if (ans & (1 << i)) printf("%d ", i + 1);
        puts("");
    }
    return 0;
}