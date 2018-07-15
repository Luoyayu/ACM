#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = static_cast<const int>(1e6 + 7);

struct node {
    int time, value;
} a[maxn];


bool cmpa(node x, node y) {
    return x.time < y.time;
}

bool cmpb(node x, node y) {
    return x.value > y.value;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%d", &a[i].time);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].value);

    int ansA = 0, ansB = 0;
    int sp = 0;
    sort(a, a + n, cmpa);
    for (int i = 0; i < n; i++) {
        if (sp + a[i].time <= m) {
            ansA += a[i].value;
            sp += a[i].time;
        } else break;
    }
    sort(a, a + n, cmpb);
    sp = 0;
    for (int i = 0; i < n; i++) {
        if (sp + a[i].time <= m) {
            ansB += a[i].value;
            sp += a[i].time;
        } else break;
    }
    if (ansA == ansB) printf("SAME\n");
    else if (ansA < ansB) printf("B\n");
    else if (ansA > ansB) printf("A\n");

}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}