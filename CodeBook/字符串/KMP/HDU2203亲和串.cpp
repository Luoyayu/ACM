//需要把子串s后面在拼接上s即可实现循环移位,思考
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
string p,s;
int Next[maxn];
int plen,slen;
void getnext()
{
	int i=0,j=Next[0]=-1;
	while(i<plen-1)
	{
		if(j==-1||p[i]==p[j])
			Next[++i] = ++j;
		else
			j = Next[j];
	}
}
bool kmp()
{
    getfailure();
    getnext();
    int i=0,j=0;
    while(i<slen)
    {
        if(j==-1||s[i]==p[j])
            i++,j++;
        else
            j=Next[j];
        if(j==plen)
            return true;
    }
    return false;
}
using namespace std;
int main()
{
    while(cin>>s>>p)
    {
        plen=p.length(),slen=s.length();
        if(plen>slen)
        {
            printf("no\n");
            continue;
        }
        s+=s,slen*=2;
        if(kmp())
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
