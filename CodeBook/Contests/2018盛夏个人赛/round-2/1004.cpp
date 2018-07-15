#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve();

string s[107], s1[100], s2[1000], s3[20000];
int cnt1 = 0, cnt2 = 0, cnt3 = 0;

int main() {
    for (int i = 0; i < 26; i++) s1[cnt1++] = i + 'a';

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            s2[cnt2] += i + 'a';
            s2[cnt2++] += j + 'a';
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                s3[cnt3] += i + 'a';
                s3[cnt3] += j + 'a';
                s3[cnt3++] += k + 'a';
            }
        }
    }

    int Kase;
    scanf("%d", &Kase);
    while (Kase--) {
        solve();
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < cnt1; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (s[j].find(s1[i]) != string::npos) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << s1[i] << endl;
            return;
        }
    }

    for (int i = 0; i < cnt2; i++) {  // "ac"
        int flag = 1;
        for (int j = 0; j < n; j++) {                // "a" , "acc"
            if (s[j].find(s2[i]) != string::npos) {  // 有
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << s2[i] << endl;
            return;
        }
    }

    for (int i = 0; i < cnt3; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (s[j].find(s3[i]) != string::npos) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << s3[i] << endl;
            return;
        }
    }
}