#include<bits/stdc++.h>
using namespace std;
char p[1005][1005];
int w[1005];
int kmpnext[1005][1005];
int getnext(const int *x,int len)
{
    int j = Next[0]= -1,i = 0;
    while (i < len)
    {
        while (j!= -1 &&  x[i] != x[j])//x[i]表前缀，p[j]表后缀匹配失败
            j = Next[j];
        if (x[++i] == x[++j])//*
            Next[i] = Next[j];
        else Next[i] = j;//*
    }
}
int kmp(const char *s,const char *s)
{
    int plen = strlen(p),slen=strlen(s);
    int i=0,j=0;
    int flag=0;
    while(i<plen)
    {
         while (j!= -1 && s[i] != p[j])
            j = Next[j];
        i++; j++;
        if (j >= plen)
        {
            flag=1;
            break;
        }
        
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s %d",p ,&w),strrev(p),getkmp(p,strlen(p));
        
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int x,y,z;
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d%d",&y,&z);
                w[y]=z;
            }
            else
            {
                
            }
        }
        

    }
}