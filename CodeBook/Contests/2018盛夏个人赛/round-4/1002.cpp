#include <bits/stdtr1c++.h>
#include <utility>

using namespace std;
const int maxn = 1e5 + 7;
// MLE
string s[maxn];
map<string, string> mp_raw;
map<string, int> mp_idx;
vector<string> v[maxn];
map<string, bool> st;

void addIntoVector(int idx, const string &Q) {
    int curFuncNameIdx = mp_idx[Q];
    unsigned long len = s[curFuncNameIdx].length();

    for (int i = 0; i < len;) {
        int funcNameSt = 0, funcNameEd = 0;
        if (string(s[curFuncNameIdx], static_cast<unsigned long>(i), 4) == "with") {
            funcNameSt = i + 5;
            for (int j = funcNameSt; j < len; j++)
                if (s[curFuncNameIdx][j] == ' ') {
                    funcNameEd = j;
                    break;
                }
            v[idx].emplace_back(s[curFuncNameIdx], funcNameSt, funcNameEd - funcNameSt);
            i = funcNameEd;
        } else i++;
    }
}

int bfs(const string &Q, int cnt) {
    queue<string> q;
    q.push(Q);
    v[++cnt].push_back(Q);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        addIntoVector(++cnt, cur);
        for (const auto &x:v[cnt])
            q.push(x);
        v[cnt].insert(v[cnt].begin(), cur);
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        mp_raw.clear();
        mp_idx.clear();
        st.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) v[i].clear();
        getchar();
        for (int i = 0; i < n; i++) {
            getline(cin, s[i]);
            auto len = static_cast<int>(s[i].length());
            string funcName;
            int funcNameSt = 4, retVal = 0;
            int j;
            for (j = 4; j < len; j++) if (s[i][j] == ' ') break;
            funcName = string(s[i], 4, static_cast<unsigned long>(j - 4));
            mp_idx[funcName] = i;
            for (j = len - 1; j >= 4; j--) if (s[i][j] == '=') break;
            mp_raw[funcName] = string(s[i], static_cast<unsigned long>(j + 2),
                                      static_cast<unsigned long>(len - (j + 2)));
        }
        string Q;
        cin >> Q;
        int cnt = bfs(Q, -1);
        stack<string> stk;
        for (int i = cnt - 1; i >= 0; i--) {
            for (auto it = v[i].rbegin(); it != v[i].rend(); it++) {
                string x = *it;
                if (!st[x]) {
                    stk.push(x);
                    st[x] = true;
                }
            }
        }
        cout << mp_raw[stk.top()];
        stk.pop();
        while (!stk.empty()) {
            cout << " " << mp_raw[stk.top()];
            stk.pop();
        }
        cout << endl;
    }
}
