#include<bits/stdc++.h>
const int maxn = 1000+9;
int king[maxn],tian[maxn];
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&tian[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&king[i]);
        sort(king,king+n);sort(tian,tian+n);

        int bestOfTian = n-1,bestOfKing = n-1;
        int lastOfTian = 0, lastOfKing = 0;
        int cnt = 0;
        while(lastOfTian<=bestOfTian)
        {
            if(tian[bestOfTian]>king[bestOfKing])
            {
                cnt++;
                bestOfTian--,bestOfKing--;
            }
            else if(tian[bestOfTian]<king[bestOfKing])
            {
                bestOfKing--;
                lastOfTian++;
                cnt--;
            }
            else if(king[bestOfKing]==tian[bestOfTian] && king[lastOfKing]<tian[lastOfTian])
            {
                cnt++;
                lastOfTian++,lastOfKing++;
            }
            else if(king[bestOfKing]==tian[bestOfTian] && king[lastOfKing]>=tian[lastOfTian])
            {
                if(tian[lastOfTian]<king[bestOfKing])
                {
                    cnt--;
                }
                else if(tian[lastOfTian]>king[bestOfKing])
                {
                    cnt++;
                }

                lastOfTian++,bestOfKing--;
            }
        }
        printf("%d\n",cnt*200);
    }
    return 0;
}
