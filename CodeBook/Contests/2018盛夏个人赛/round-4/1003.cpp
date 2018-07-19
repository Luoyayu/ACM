#include <bits/stdtr1c++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll sum = 0;
        bool flag = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x >= n) flag = 1;
            sum += x;
        }
        if (sum % 2 || flag) puts("N");
        else puts("Y");
    }
}