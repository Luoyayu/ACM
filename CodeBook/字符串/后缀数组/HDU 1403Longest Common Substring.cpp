//HDU 1403 Longest Common Substring
//求多个字符串的最长连续子串长度
//我是谁？我在哪儿？
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 200000+500;
int wa[maxn],wb[maxn],wv[maxn],WS[maxn],r[maxn];
int Rank[maxn],height[maxn],sa[maxn];
char str[2*maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) WS[i]=0;
    for(i=0; i<n; i++) WS[x[i]=r[i]]++;
    for(i=1; i<m; i++) WS[i]+=WS[i-1];
    for(i=n-1; i>=0; i--) sa[--WS[x[i]]]=i;
    for(p=1,j=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) WS[i]=0;
        for(i=0; i<n; i++) WS[wv[i]]++;
        for(i=1; i<m; i++) WS[i]+=WS[i-1];
        for(i=n-1; i>=0; i--)
            sa[--WS[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++ )
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++)
        Rank[sa[i]]=i;
    for(i=0; i<n; height[Rank[i++]]=k)
        for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        int len1=len;
        str[len]='9';
        scanf("%s",str+len1+1);
        len=strlen(str);
        for(int i=0;i<len;i++)
            r[i]=str[i];
        r[len]=0;
        da(r,sa,len,200);
        calheight(r,sa,len);
        int maxint=0;
        for(int i=2; i<len; i++)
            if(maxint<height[i])
                if((sa[i]>len1&&sa[i-1]<len1)||(sa[i]<len1&&sa[i-1]>len1))
                    maxint=height[i];
        printf("%d\n",maxint);
    }
    return 0;
}
