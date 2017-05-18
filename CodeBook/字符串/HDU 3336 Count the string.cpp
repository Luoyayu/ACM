//KMP+DP
#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
const int maxn=200005;
char p[maxn];
int plen;
int Next[maxn];
void getnext()
{
	int i=0,j=Next[0]=-1;
	for(int i=0;i<plen-1;i++)
	{
		if(j==-1||p[i]==p[j])
			i++,j++,Next[i] = j;
		else
			j = Next[j];
	}
	//for(int i=0;i<plen;i++)
    //    printf("%d ",Next[i]);
    //printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d",&plen);
        scanf("%s",p);
        getnext();
        for (int i=1;i<plen;i++ )
        {
            int q=i;
            while(q!=-1)
            {
                q = Next[q];
                ans++;
                ans%=mod;
            }
        }
        printf("%d\n",(ans+1)%mod);
    }
    return 0;
}

