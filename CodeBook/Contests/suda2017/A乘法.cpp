#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+7;
int main()
{
    int t;scanf("%d",&t);
    int a,b,x,y;
    while(t--)
    {
        scanf("%d %d",&x,&y);
        int MINa=99999,MINb=99999,MINtot=99999;
        for(int i=1;i<=maxn;i++)
            for(int j=1;j<=maxn;j++)
                if(i*j%x==y)
                    if(i+j<MINtot)
                        MINa=i,MINb=j,MINtot=i+j;
        printf("%d %d\n",MINa,MINb);
    }
    return 0;
}
