#include<bits/stdc++.h>
using namespace std;
#define Debug(x) cout<<#x<<"= "<<x<<endl;
const int maxn=100055;
char p[maxn];
int Next[maxn];
int plen;
void getnext()
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<plen)
    {
        while(j!=-1&&p[i]!=p[j])
            j=Next[j];
        Next[++i]=++j;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",p);
        plen=strlen(p);
        getnext();//Next[plen]为最小循环节
        int L=plen-Next[plen];
        if(plen%L==0&&L!=plen)//L为自身长度要排除
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",L-plen%L);
    }
    return 0;
}
