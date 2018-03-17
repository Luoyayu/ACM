#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    while (a && b) {
        if (a >= (b << 1)) a %= (b << 1);
        else if (b >= (a << 1)) b %= (a << 1);
        else break;
    }
    return !printf("%lld %lld\n", a, b);
}