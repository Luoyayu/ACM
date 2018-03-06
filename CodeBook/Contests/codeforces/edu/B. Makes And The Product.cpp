
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7,N=1e6+7,MOD=1e9+9;;
LL num[maxn];
LL C(LL a, LL b)
{
	LL i, j, k;
	LL A = 1;
	LL D = 1;
	LL c = a - b;
	for (i = a; i > c; i--)
		A *= i;
	for (i = 1; i <= b; i++)
		D *= i;
	return A/D;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
           scanf("%I64d",&num[i]);
        sort(num,num+n);

        if(num[0]==num[1]&&num[0]==num[2])
        {
            LL tmp=num[0];
            LL cnt=3;
            for(int i=3;i<n;i++)
                if(num[i]==tmp)
                    cnt++;
            printf("%I64d\n",C(cnt,3));
            return 0;
        }
        else if(num[1]!=num[2])//1 2 3 3
        {
            LL tmp=num[2];
            LL cnt=1;
            for(int i=3;i<n;i++)
                if(num[i]==tmp)
                    cnt++;
            printf("%I64d\n",cnt);
            return 0;
        }
        else if(num[1]==num[2])
        {
            LL tmp=num[2];
            LL cnt=2;
            for(int i=3;i<n;i++)
                if(num[i]==tmp)
                    cnt++;
            printf("%I64d\n",C(cnt,2));
            return 0;
        }
    }
    return 0;
}
