#include <bits/stdc++.h>

using namespace std;
string s;

int main() {
    cin >> s;
    char st = 'a';
    for (int i = 0; i < s.length() && st <= 'z'; i++) {
        if (st >= s[i])
            s[i] = st++;
    }
    if (st <= 'z') puts("-1");
    else cout << s << endl;
}