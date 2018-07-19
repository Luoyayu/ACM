#include <bits/stdtr1c++.h>

using namespace std;
typedef long long ll;
const int maxn = static_cast<const int>(1e5 + 7);

void solve();


int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
        solve();
}

ll a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    ll ans = 0;
    for (int i = 1; i < n; i++)
        ans += a[0] + a[i];
    printf("%lld\n", ans);
}

/*
Problem Description
There are n cities in Byteland, and the ith city has a value ai. The cost of building a bidirectional road between two cities is the sum of their values. Please calculate the minimum cost of connecting these cities, which means any two cities can reach each other.
 

Input
The first line is an integer T(T≤105), representing the number of test cases.
For each test case, the first line is an integer n(n≤105), representing the number of cities, the second line are n positive integers ai(ai≤105), representing their values.
 

Output
For each test case, output an integer ans, the minimum cost of connecting these cities.
 

Sample Input
2
4
1 2 3 4
1
1
 

Sample Output
12
0
*/