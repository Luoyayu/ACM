#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
const double pi=acos(double(-1));

int main()
{
	int n,m;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		map<string,int>mp;
		string str;
		for(int j=0;j<n;j++)
		{	
			cin>>str;
			for(int i=0;i<str.size();i++)
				str[i]=tolower(str[i]);
			mp[str]++;
		}
		for(int i=0;i<m;i++)
		{
			cin>>str;
			for(int j=0;j<str.size();j++)
				str[j]=tolower(str[j]);
			mp.erase(str);
		}
		cout<<mp.size()<<endl;
	}
	return 0;
}