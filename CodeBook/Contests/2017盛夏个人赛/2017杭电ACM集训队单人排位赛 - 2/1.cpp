#include<bits/stdc++.h>
#define Debug(x) cout<<#x<<"= "<<x<<endl;
using namespace std;
const int maxn=10000+7;
int n, m, k;
struct SSS
{
    int id ,totAC, totTime;
    int ac[12], PASS[12];
    char name[25];
    SSS()
    {
        totAC =totTime = 0;
        memset(ac,0,sizeof ac);
        memset(PASS,0,sizeof PASS);
    }

    bool operator < (const SSS &b) const
    {
        if(totAC!=b.totAC)
            return totAC > b.totAC;
        if(totTime!= b.totTime)
            return totTime < b.totTime;
        return id < b.id;
    }
}stu[maxn];

int main()
{
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%s",stu[i].name),stu[i].id = i;
        for(int i=1;i<=m;i++)
        {
            int totTime, id, passid;
            char Result[5];
            scanf("%d%d%d%s",&totTime,&id,&passid,Result);
            if(Result[0] == 'A')
                {
                    if(!stu[id].ac[passid])
                    {
                        stu[id].ac[passid] = 1,stu[id].totAC++;
                        stu[id].totTime += totTime + 20 * stu[id].PASS[passid];
                    }
                }
            else if(Result[0] == 'W'&&(!stu[id].ac[passid]))
                    stu[id].PASS[passid]++;
        }
        sort(stu+1,stu+n+1);
        for(int i=1;i<=n;i++)
            printf("%s %d %d\n",stu[i].name,stu[i].totAC,stu[i].totTime);
    }
    return 0;
}
