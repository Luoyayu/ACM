#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAX_N=10010;
const int INF=0x3f3f3f3f;
char a[100010],b[100010];
int nex[100010];
int n,m;
void getnext()
{
        int j,k;
        j=0,k=-1;
        nex[0]=-1;
        while(j<m)
        {
                if(k==-1||b[j]==b[k])
                        nex[++j]=++k;
                else k=nex[k];
        }
}
int kmp_index()
{
        int i=0,j=0;
        getnext();
        while(i<n&&j<m)
        {
                if(j==-1||a[i]==b[j])
                        i++,j++;
                else j=nex[j];
        }
        if(j==m) return 1;
        else return -1;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                memset(a,0,sizeof(a));
                memset(b,0,sizeof(b));
                memset(nex,0,sizeof(nex));
                scanf("%s",a);
                scanf("%s",b);
                n=strlen(a);
                m=strlen(b);
                int l=m;
                for(int i=l-1;i>=0;i--)
                {
                        if(b[i]=='0')
                        {
                             m--;
                        }
                        else break;
                }
                if(n<m) printf("Bob\n");
                else if(m==0) printf("Alice\n");
                else
                {
                        if(kmp_index()==1) printf("Alice\n");
                        else
                        {
                                for(int i=0;i<m-i-1;i++)
                                        swap(b[i],b[m-i-1]);

                                if(kmp_index()==1) printf("Alice\n");
                                else printf("Bob\n");
                        }
                }
        }
}