#include <bits/stdtr1c++.h>
#include "feature.h"

#define time TIME
using namespace std;
struct Time {
    int a;
    double p;
    double ct;
} time[100];

bool cmp(Time a, Time b) { return a.ct < b.ct; }

int main() {
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> time[i].a;
        cin >> time[i].p;
        sum += time[i].p;
    }
    for (int i = 0; i < n; i++) time[i].ct = time[i].a * time[i].p / sum;
    sort(time, time + n, cmp);
    double ans = 0;
    for (int i = 0; i < n; i++) ans += time[i].ct * (n - i);
    cout << ans << endl;
}
