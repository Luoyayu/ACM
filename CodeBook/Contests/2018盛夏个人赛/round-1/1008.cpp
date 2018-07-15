#include <bits/stdtr1c++.h>

using namespace std;

map<string, string> mp;  // a b
map<string, int> usd;    // a b(int)
set<string> s;

int check(string &s) {  // 0 string
    auto lens = s.length();
    if ((s[0] < '0' || s[0] > '9') && s[0] != '-') return 0;
    if (s[0] != '0') return 1;  // no like 000123
    int i = 0;
    for (; i < lens; i++)
        if (s[i] != '0') break;
    if (i == s.length()) {
        s = "0";
        return 1;
    }
    string temp(&s[i], static_cast<unsigned long>(s[lens]));
    s = temp;
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        mp.clear();
        usd.clear();
        s.clear();
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            auto lena = a.length(), lenb = b.length();
            // a b
            // T 2
            // T N
            if (s.count(a) == 0) {
                s.insert(a);
                usd[(mp[a] = check(b) ? b : mp[b])]++;
            } else {                  // 重新声明或引用
                if (check(b) == 1) {  // T 2
                    if (mp[a] != b) {
                        usd[(mp[a])]--;
                        usd[(mp[a] = b)]++;
                    }
                } else if (mp[a] != mp[b]) {
                    usd[(mp[a])]--;
                    usd[(mp[a] = mp[b])]++;
                }
            }
        }
        int ans = 0;
        for (auto x : usd)
            if (x.second) ans++;
        printf("%d\n", ans);
    }
}