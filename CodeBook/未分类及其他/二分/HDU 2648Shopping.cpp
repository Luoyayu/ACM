//STL 做法
#include<bits/stdc++.h>
#define rank Rank
using namespace std;
int main()
{
    int n,m,p;
    string s;
    while(cin>>n)
    {
        map<string,int> shop;
        while(n--)
        {
            cin>>s;
            shop[s]=0;
        }
        cin>>m;
        while(m--)
        {
            while(n--)
            {
                cin>>p>>s;
                shop[s]+=p;
            }

            int favor=shop["memory"];
            int rank=1;

            map<string,int>::iterator it;
            for(it=shop.begin();it!=shop.end();it++)
                if(it->second > favor) rank++;
            cout<<rank<<endl;
        }
        shop.clear();
    }
    return 0;
}
