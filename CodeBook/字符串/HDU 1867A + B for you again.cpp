#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
char s[maxn],p[maxn];
int Next[maxn];
void getnext(const char *x, int xlen)
{
	int i=0,j=Next[0]=-1;
	while(i<xlen)
	{
		if(j==-1||x[i]==x[j])
			i++,j++,Next[i] = j;
		else
			j = Next[j];
	}
}
int KMP(const char *s,int slen,const char *p,int plen)
{
    int ans=0;
    getnext(p,plen);
    int i=0,j=0;
    while(i<slen)
    {
        while(j!=-1 && s[i]!=p[j])
            j=Next[j];
        i++,j++;
    }
    return (j==-1)?0:j;
}
int main()
{
    while(scanf("%s %s",s,p)!=EOF)
    {
        int slen = strlen(s), plen = strlen(p);
        int t = min(slen,plen);
        int lsp = KMP(s,slen,p,plen);
        int lps = KMP(p,plen,s,slen);
        if(lsp > lps)
        {
            s[slen-lsp] = '\0';
            printf("%s%s\n",s,p);
        }
        else if(lsp < lps)
        {
            p[plen-lps] = '\0';
            printf("%s%s\n",p,s);
        }
        else if(lsp == 0)
        {
            string str1(s);str1 += p;
            string str2(p);str2 += s;
            cout<<min(str1,str2)<<endl;
        }
        else
        {
            char t1;
            t1 = s[slen-lsp];
            s[slen-lsp] = '\0';
            string str1(s);
            str1 += p;
            s[slen-lsp] = t1;
            p[plen-lps] = '\0';
            string str2(p);
            str2 += s;
            cout<<min(str1,str2)<<endl;
        }
    }
    return 0;
}
