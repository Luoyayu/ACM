#include <bits/stdc++.h>
//抄标算的话说STL真好看
//题意就是把一个a序列和a序列任意两个元素加和形成的b序列混在一起
//还原a序列;
//思想就是对b序列排序那么最小a1的一定在a中,删去ab序列中的a1,在从ab序列中拿出最小的和a序列的所有元素加和删去ab序列中相应的数
using namespace std;
vector<int> ab, a;
map<int,int> p;//好使啊
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        ab.clear(),a.clear(),p.clear();
        for(int i=0;i<m;i++)
        {
            int x;scanf("%d",&x);p[x]++;
            ab.push_back(x);
        }
        sort(ab.begin(),ab.end());
        a.push_back(ab[0]);p[a[0]]--;
        for(int i=1;i<ab.size();i++)//每次取出ab中最小元素，和a中的元素组合删去ab中的元素
        {
            if(p[ab[i]]==0) continue;
            for(int j=0;j<a.size();j++)
                p[ab[i]+a[j]]--;
            a.push_back(ab[i]);//放进a中最后再删掉
            p[ab[i]]--;
        }
        printf("%d\n",a.size());
        for(int i=0;i<a.size();i++)
            printf("%d%c",a[i],i==a.size()-1?'\n':' ');
    }
    return 0;
}