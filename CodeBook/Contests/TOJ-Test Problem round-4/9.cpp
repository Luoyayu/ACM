#include<bits/stdc++.h>
//I 题 sb了 忘了关a数组 T了2遍
using namespace std;
const int maxn = 1e7;
int diff[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        scanf("%d",&diff[0]);
        int sum = 0,maxsum = 0;
        for(int i=1;i<n;i++)
        {

            scanf("%d",&diff[i]);
            diff[i-1]=diff[i]-diff[i-1];
            sum+=diff[i-1];
            if(sum>maxsum)
                maxsum = sum;
            if(sum<0)
                sum=0;
        }
        printf("%d\n",maxsum);
    }
    return 0;
}
