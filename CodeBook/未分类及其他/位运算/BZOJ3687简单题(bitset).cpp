// TODO:BZOJ 3687
#include <bitset>
#include <cstdio>
using namespace std;
bitset<2000000> bi;  // bitset常用在集合操作求集合的交集用按位与,求集合并集按位或
//题意:求子集算数和的异或和
// 1 3 2
// ans = 1 ^ (1+3) ^ (1+3+2) ^ 3 ^ (3+2) ^2
int main() {
    //异或xor 不同为1不带进位的加法半加运算
    /* bi.reset();//全置为0可选参数pos
     bi.set();//全置为1,可选参数pos
     bi.flip();//取反,可选参数pos
     bi.any();//return 是否存在1
     bi.count();//计1的位数*/
    int n, x, sum = 0, ans = 0;
    scanf("%d", &n);
    bi[0] = 1;
    while (n--) {
        scanf("%d", &x);
        sum += x;
        bi ^= (bi << x);
    }
    for (int i = 1; i <= sum; i++)
        if (bi[i]) ans ^= i;
    printf("%d\n", ans);
    return 0;
}
