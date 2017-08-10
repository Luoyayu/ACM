#include <bits/stdc++.h>
//set+map
using namespace std;
map<string,int> f,s;
set<string> c;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        f.clear();s.clear();
        c.clear();
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            string name;
            int value;
            cin>> name >> value;
            c.insert(name);
            s[name]=value>s[name]?value:s[name];
            if(s[name]>f[name]) swap(s[name],f[name]);
        }
        int sum = 0;
        for(set<string>::iterator it=c.begin();it!=c.end();it++)
            sum +=s[*it]+f[*it];
        printf("%d\n",sum);
    }
    return 0;
}