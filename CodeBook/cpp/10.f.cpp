#include<bits/stdc++.h>
using namespace std;
const double pi=acos(double(-1));
bool cmp(string a,string b)
{
	return a+b < b+a;
}
int main()
{
	int n,T;
	scanf("%d",&T);
	while(T--)
	{
		string tmp;
		vector<string> s;
		cin>>n;
		while(n--)
		{
			cin>>tmp;
			s.push_back(tmp);
		}
		sort(s.begin(),s.end(),cmp);
		for(int i=0;i<s.size();i++)
			cout<<s[i];
		cout<<endl;

	}
	return 0;
}