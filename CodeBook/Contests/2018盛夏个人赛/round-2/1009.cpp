#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
const int maxn = 1e6 + 7;

void solve();

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}

int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int pred[] = {0,  0,  1,  7,  4,   2,   6,   8,   10,  18, 22,
              20, 28, 68, 88, 108, 188, 200, 208, 688, 888};
void solve() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%1d", &x);
        sum += cnt[x];
    }
    //    debug(sum);

    int yu = 0;
    if (sum > 17) {
        while (sum) {
            if (sum <= 17) {
                cout << pred[sum];
                break;
            }
            yu++;
            sum -= 7;
        }
        while (yu--) cout << 8;
        cout << endl;
    } else
        cout << pred[sum] << endl;
}

/*
题意: LED的数字占用的光线: int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
给出一个数字串 abcd..edf
问:在总光线数不变的情况下,能组成的最小的数
*/

// FIXME: TODO: TRICK: NOTE: 思路: 题意: ACM