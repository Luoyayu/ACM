#include<bits/stdc++.h>
///分类==POI, 分块加速
///给出a,b,c,d;找出(i,j) 使得gcd(i,j)最大
///枚举答案t=gcd(i,j)，校检b/k>a/k且d/k>c/k
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,d;
        int ans=0,last;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for(int i=1;i<=b && i<=d;i=last+1)
        {
            last=min(b/(b/i),d/(d/i));
            #ifdef Local
            cout<<"now i "<<i<<">> b/(b/i):"<<b/(b/i)<<" >> d/(d/i): "<<d/(d/i)<<endl;
            cout<<"last: "<<last<<endl;
            #endif // Local
            if(b/last>(a-1)/last&&d/last>(c-1)/last)//有解则该gcd满足
                ans=max(ans,last);
        }
        printf("%d\n",ans);
    }
    return 0;
}
