#include<bits/stdc++.h>
using namespace std;
char str[100000+5];
typedef long long ll;
ll a[8];
int main()
{

    while (scanf("%s", str)!=EOF)
    {
        /*
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
        /*
        a[5]=a[5]/2;//正确姿势
        long long m=100000;
        for (int i=1;i<=7;i++)
            m=min(a[i],m);
        printf("%d\n",m);
    }
    */
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
        sort(a,a+6);//居然这样写会超时醉了小数据还是别用sort了
        printf("%d\n",a[0]);
    }
    return 0;
}
