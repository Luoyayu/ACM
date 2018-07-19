#include <bits/stdtr1c++.h>

using namespace std;
const int maxn = 1e6 + 7;

//void SplitString(const string &s, vector<string> &v, const string &c) {
//    string::size_type pos1, pos2;
//    pos2 = s.find(c);
//    pos1 = 0;
//    while (string::npos != pos2) {
//        v.push_back(s.substr(pos1, pos2 - pos1));
//
//        pos1 = pos2 + c.size();
//        pos2 = s.find(c, pos1);
//    }
//    if (pos1 != s.length())
//        v.push_back(s.substr(pos1));
//}
//
//string s;
//vector<string> v;
//
//void solve() {
//    v.clear();
//    getline(cin, s);
//    SplitString(s, v, " ");
//
//    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
//        string raw = v[i];
//        int len = v[i].length();
//        int la = 0;
//        for (int j = len - 1; j >= 0; j--) {
//            char lastch = raw[j];
//            if (lastch == ',' || lastch == ' ' || lastch == '-' || lastch == '.')
//                la++;
//        }
//        reverse(raw.begin(), raw.end() - la);
//        printf("%s%c", raw.c_str(), i == v.size() - 1 ? '\n' : ' ');
//    }
//}
void Print(const string &s) {
    int len = s.length();
    if (len == 0) return;
    for (int i = len - 1; i >= 0; --i)
        printf("%c", s[i]);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char c;
    string s;
    while (scanf("%c", &c) != EOF) {
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != '-')) {
            Print(s);
            s.clear();
            printf("%c", c);
        } else s.push_back(c);
    }
    return !printf("\n");
}