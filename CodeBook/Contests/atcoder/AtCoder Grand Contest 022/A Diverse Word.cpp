#include <bits/stdtr1c++.h>

using namespace std;
set<char> st;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) st.insert(s[i]);
    if (len != 26) { //给出的多样字符串最长为26
        cout << s;
        for (char i = 'a'; i <= 'z'; i++) {
            if (st.count(i)) continue;
            cout << i << endl;
            return 0;
        }
    }
    string s2 = s;
    if (!next_permutation(s2.begin(), s2.end())) return !printf("-1\n");// 输出下一种排列
    for (int i = 0; i < len; i++) {
        printf("%c", s2[i]);
        if (s2[i] != s[i]) break; //按要求截断
    }
    puts("");
}