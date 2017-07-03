#include<bits/stdc++.h>
//可以把一个序列搞成数字在比较即可
const int maxn=1e6+7;
using namespace std;
int p1[10],p2[10],p3[10];
int cmp(int *a,int *b)
{
    int flag=0;
    for(int i=1;i<8;i++)
    {
        if(a[i]>b[i])
            return 1;
        if(b[i]>a[i])
            return -1;
    }
        return 0;
}
int main()
{
    int p;
    int cnt=0;
    while(scanf("%d",&p1[1])!=EOF)
    {
        for(int i=2;i<=8;i++)
            scanf("%d",&p1[i]);
        for(int i=1;i<=8;i++)
            scanf("%d",&p2[i]);
        for(int i=1;i<=8;i++)
            scanf("%d",&p3[i]);
        int TMP=cmp(p1,p2);
        if(TMP==0||TMP==1)//p1>=p2
        {
            int cc=cmp(p1,p3);
            if(cc==-1)
                puts("3");
            else if(cc==0) puts("1");
            else puts("1");
        }
        else //p1<p3
        {
            int cc=cmp(p2,p3);
            if(cc==-1)
                puts("3");
            else if(cc==0)
                puts("2");
            else puts("2");
        }
    }
    return 0;
}
