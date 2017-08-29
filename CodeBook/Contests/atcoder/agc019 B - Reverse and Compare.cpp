#include <bits/stdc++.h>
//题意：给出字符串选定翻转区间[i,j] 问不同的字符串有多少种?
//数据规模length<= 2e5
//想歪了没想到5min能过的题真的不用算法
//起初想搞一个dp回文串数量再说复杂度也是瞎搞O(n^2),
//下面是标算
using namespace std;
typedef long long ll;
string s;
ll ret;
ll num[26];
int main()
{
    ios::sync_with_stdio(false);
	cin >> s;
	for(int i=0;i<s.size();i++)
		num[s[i]-'a']++;
	for(int i=0;i<26;i++)
		ret += num[i] * (s.size() - num[i]);
	cout << ret / 2 + 1 << endl;
	return 0;
}