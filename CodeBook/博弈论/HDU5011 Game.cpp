#include<bits/stdc++.h>
//本质和Nim博弈一样,每次取完石子的操作再把任一堆分开
//如果现在已经处于必胜状态
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
int p[maxn],n;
bool Nim_game()
{
    int flag=0;
    for(int i=0;i<n;i++)
        flag^=p[i];
    if(flag)
        return 1;
    return 0;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&p[i]);

        if(Nim_game())
            printf("Win\n");
        else
            printf("Lose\n");
    }
    return 0;
}
