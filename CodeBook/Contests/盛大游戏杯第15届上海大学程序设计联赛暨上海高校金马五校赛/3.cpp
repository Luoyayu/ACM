#include<bits/stdc++.h>
using namespace std;
#define y2 Y2
#define next Next;
#define lowbit(x) x&(-x)
#define IOS std::ios::stdio(flase)
#define clr(x,num) memset(x,num,sizeof(x));
#define Debug(x) cout<<#x<<" = "<<x<<endl;
typedef long long ll;
const int maxn = 1e5 + 7;
const int maxc = 1e3 + 5;
const int maxr = 1e5 + 5;
const int MOD  = 1e9 + 7;
const int inf  = 0x3f3f3f3f;
const double esp = 1e-6;
const double pi = acos(-1);
char st1[100000+5];
int a[8];
int main()
{

        while (scanf("%s", st1)!=EOF)
	{
		memset(a,0,sizeof(a));
		int len = strlen(st1);
		for (int i=0;i<len;i++)
		{
			if (st1[i]=='i'||st1[i]=='I') a[1]++;
			else if (st1[i]=='l'||st1[i]=='L') a[2]++;
			else if (st1[i]=='o'||st1[i]=='O') a[3]++;
			else if (st1[i]=='v'||st1[i]=='V') a[4]++;
			else if (st1[i]=='e'||st1[i]=='E') a[5]++;
			else if (st1[i]=='c'||st1[i]=='C') a[6]++;
			else if (st1[i]=='s'||st1[i]=='S') a[7]++;

		}
		a[5]=a[5]/2;
		long long m=100000;
		for (int i=1;i<=7;i++)
		if (a[i]<m) m=a[i];

		printf("%d\n",m);
	}

        /*
        int len = strlen(str);
        memset(a,0,sizeof a);
        for(int i=0;i<len;i++)
        {
            if(str[i]=='E'||str[i]=='e')      a[0]++;
            else if(str[i]=='I'||str[i]=='i') a[1]++;
            else if(str[i]=='L'||str[i]=='l') a[2]++;
            else if(str[i]=='O'||str[i]=='o') a[3]++;
            else if(str[i]=='V'||str[i]=='v') a[4]++;
            else if(str[i]=='C'||str[i]=='c') a[5]++;
            else if(str[i]=='S'||str[i]=='s') a[6]++;
        }


        a[0]/=2;
        sort(a,a+6);
        printf("%d\n",a[0]);
        */
    return 0;
}
