//利用next[]求循环节长度
#include<bits/stdc++.h>
using namespace std;
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
        if(j==-1||p[i]==p[j])
            Next[++i]=++j;
        else
            j=Next[j];
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
        getnext();
        int L=plen-Next[plen];//
        if(plen%L==0 && L!=plen)//
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",L-plen%L);
    }
    return 0;
}
