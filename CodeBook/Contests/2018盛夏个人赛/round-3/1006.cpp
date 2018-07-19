#include <bits/stdc++.h>

using namespace std;
#define xx mv = max(0LL, mr - ml + 1);
#define xxx mvv = max(0LL, mrr - mll + 1);
const int mod = 1e9 + 7;
typedef long long ll;

inline ll mul2mod(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }

inline ll mul3mod(ll x, ll y, ll z) { return mul2mod(x, mul2mod(y, z)); }

inline ll mul4mod(ll x, ll y, ll z, ll zz) { return mul2mod(zz, mul3mod(x, y, z)); }


inline ll add2mod(ll x, ll y) { return (x % mod + y % mod) % mod; }

inline ll add3mod(ll x, ll y, ll z) { return add2mod(x, add2mod(y, z)); }


inline ll sub2mod(ll x, ll y) { return (x - y + mod) % mod; }


inline ll max3(ll x, ll y, ll z) { return max(x, max(y, z)); }

inline ll max4(ll x, ll y, ll z, ll zz) { return max(max3(x, y, z), zz); }


inline ll min3(ll x, ll y, ll z) { return min(x, min(y, z)); }

inline ll min4(ll x, ll y, ll z, ll zz) { return min(min3(x, y, z), zz); }

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll l1, l2, l3, l4;
        ll r1, r2, r3, r4;
        cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3 >> l4 >> r4;
        ll len1 = r1 - l1 + 1;
        ll len2 = r2 - l2 + 1;
        ll len3 = r3 - l3 + 1;
        ll len4 = r4 - l4 + 1;
        ll ans = mul4mod(len1, len2, len3, len4);

        // 偶数

        // 1==2
        ll ml, mr, mv, mll, mrr, mvv;
        ml = max(l1, l2), mr = min(r1, r2); xx
        // ans = ans - mv*len3*len4
        ans = sub2mod(ans, mul3mod(mv, len3, len4));

        // 2==3
        ml = max(l2, l3), mr = min(r2, r3); xx
        // ans = ans - mv *len4*len1
        ans = sub2mod(ans, mul3mod(mv, len1, len4));

        // 3==4
        ml = max(l3, l4), mr = min(r3, r4); xx
        // ans = ans - mv *len1*len2
        ans = sub2mod(ans, mul3mod(mv, len1, len2));

        // 1==4
        ml = max(l1, l4), mr = min(r1, r4); xx
        // ans = ans - mv *len2*len3
        ans = sub2mod(ans, mul3mod(mv, len2, len3));


        // 奇数

        // 1==2==3
        ml = max3(l1, l2, l3), mr = min3(r1, r2, r3); xx
        // ans = ans + mv*len4
        ans = add2mod(ans, mul2mod(mv, len4));

        // 1==2==4
        ml = max3(l1, l2, l4), mr = min3(r1, r2, r4); xx
        // ans = ans + mv*len3
        ans = add2mod(ans, mul2mod(mv, len3));

        // 1==3==4
        ml = max3(l1, l3, l4), mr = min3(r1, r3, r4); xx
        // ans = ans + mv*len2
        ans = add2mod(ans, mul2mod(mv, len2));

        // 2==3==4
        ml = max3(l2, l4, l3), mr = min3(r2, r3, r4); xx
        // ans = ans + mv*len1
        ans = add2mod(ans, mul2mod(mv, len1));

        // 奇数

        // 1==2 and 3==4
        ml = max(l1, l2), mr = min(r1, r2);
        mll = max(l3, l4), mrr = min(r3, r4);
        xx xxx
        ans = add2mod(ans, mul2mod(mv, mvv));


        // 2==3 and 1==4
        ml = max(l2, l3), mr = min(r2, r3);
        mll = max(l1, l4), mrr = min(r1, r4);
        xx xxx
        ans = add2mod(ans, mul2mod(mv, mvv));

        // 偶数
        // 1==2==3==4
        ml = max4(l1, l2, l3, l4), mr = min4(r1, r2, r3, r4);
        xx
        ans = sub2mod(ans, mul2mod(mv, 3LL));

        cout << ans << endl;
    }
}
/*
2 5   2 3 4 5
3 6   3 4 5 6
2 3   2 3
5 5   5
ans = 18
 2 5 3 6 2 3 5 5
 */
