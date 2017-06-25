#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+11;
int main()
{
    int n,m;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        sum += x;
    }
    scanf("%d",&m);
    int firstMaxLeft=-1;
    bool flag=1;
    for(int i=1;i<=m;i++)
    {
        int A,B;
        scanf("%d %d",&A,&B);
        if(A>=sum&&flag)
        {
            flag=0;
            firstMaxLeft=A;
        }
        if(sum >= A && sum <= B)
        {
            printf("%d\n",sum);
            return 0;
        }
    }
    if(firstMaxLeft==-1)
    printf("-1\n");
    else
        printf("%d\n",firstMaxLeft);
    return 0;
}
