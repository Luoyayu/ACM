#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
bool mp[28][28];
short color[30];  ///颜色序号
char str[30];
int n;

void Find()  ///四色定理枚举
{
    int maxn = 0;
    for(int j=1;j<=n;j++)
        for(int Numbcolor =1;Numbcolor<=4;Numbcolor++)
        {
            int i;
            for(i=1;i<=n;i++)
                if(mp[j][i] && color[i] == Numbcolor)
                    break;    ///如果这个颜色用过 那么就不用这个颜色
            if(i > n)
            {
                color[j] = Numbcolor;  ///染这个颜色之后跳出
                break;
            }
            maxn = max(maxn,Numbcolor);
            if(maxn == 4)  ///四色优化 - 用完四色直接打印
            {
                cout<<"4 channels needed."<<endl;
                return ;
            }
        }
    maxn += 1;
    if(maxn == 1)
        cout<<"1 channel needed."<<endl;
    else
        cout<<maxn<<" channels needed."<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n,n)
    {
        memset(mp,0,sizeof mp);
        memset(color,0,sizeof color);
        for(int i=1;i<=n;i++)
        {
            cin>>str;//A:BCD
            int len=strlen(str)-1;
            for(int j=2;j<=len;j++)
                mp[str[0]-'A'+1][str[j]-'A'+1] = 1,
                mp[str[j]-'A'+1][str[0]-'A'+1] = 1;  ///建立无向图 A-1 B-2 ...
        }
        Find();
    }
    return 0;
}
