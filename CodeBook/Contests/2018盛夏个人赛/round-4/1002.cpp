#include <bits/stdtr1c++.h>
#include <utility>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int maxn = 1e5 + 7;
// MLE 中

string s[maxn];
struct node {
    string s;
    int idx;
};
map<string, node> mp;
vector<string> v;
stack<string> stk;
int visedIdxInBFS[maxn];
bool vis[maxn];

void addIntoVector(const string &Q) {
    int curFuncNameIdx = mp[Q].idx;
    unsigned long len = s[curFuncNameIdx].length();
    for (int i = 0; i < len;) {
        int funcNameSt = 0, funcNameEd = 0;
        if (string(s[curFuncNameIdx], i, 4) == "with") {
            funcNameSt = i + 5;
            for (int j = funcNameSt; j < len; j++)
                if (s[curFuncNameIdx][j] == ' ') {
                    funcNameEd = j;
                    break;
                }
            v.emplace_back(s[curFuncNameIdx], funcNameSt,
                           funcNameEd - funcNameSt);
            i = funcNameEd;
        } else
            i++;
    }
}

int bfs(const string &Q, int cnt) {
    queue<string> q;
    q.push(Q);
    v.push_back(Q);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        int before_idx = v.size() - 1;
        addIntoVector(cur);
        v.push_back(cur);
        int after_idx = v.size();
        for (int i = before_idx + 1; i < after_idx; i++) q.push(v[i]);
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        mp.clear();
        while (!stk.empty()) stk.pop();
        int n;
        cin >> n;
        getchar();
        for (int i = 0; i <= n; i++)
            v[i].clear(), vis[i] = visedIdxInBFS[i] = 0;

        for (int i = 0; i < n; i++) {
            getline(cin, s[i]);
            auto len = static_cast<int>(s[i].length());
            string funcName;
            int funcNameSt = 4, retVal = 0;
            int j;
            for (j = 4; j < len; j++)
                if (s[i][j] == ' ') break;
            funcName = string(s[i], 4, j - 4);
            mp[funcName].idx = i;
            for (j = len - 1; j >= 4; j--)
                if (s[i][j] == '=') break;
            mp[funcName].s = string(s[i], j + 2, len - (j + 2));
        }
        string Q;
        cin >> Q;
        int cnt = bfs(Q, -1);

        // stack 倒置 + 去重
        for (int i = cnt - 1; i >= 0; i--) {
            for (auto it = v.rbegin(); it != v.rend(); it++) {
                string x = *it;
                if (!vis[mp[x].idx]) {
                    stk.push(x);
                    vis[mp[x].idx] = true;
                }
            }
        }
        cout << mp[stk.top()].s;
        stk.pop();
        while (!stk.empty()) {
            cout << " " << mp[stk.top()].s;
            stk.pop();
        }
        cout << endl;
    }
}

/*
2
4
def a = pentakill
def b with a = quadrakill
def c with b = thriplekill
def d with c = doublekill
d
6
def f1 = world
def f2 = hello
def f3 with f2 with f1 = say
def f4 = please
def f5 with f3 with f4 = dont
def f6 with f3 with f2 = rather
f6
*/
