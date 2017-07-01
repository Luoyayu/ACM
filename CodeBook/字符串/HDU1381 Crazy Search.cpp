//进制hash
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=16000007;
#define hash HASH
bool hash[maxn];
char w[maxn];
int id[200];
int main()
{
    int n,nc;
    int t;
    scanf("%d",&t);
    {
        scanf("%d %d",&n,&nc);

        memset(id,-1,sizeof id);
        memset(hash,false,sizeof hash);
        scanf("%s",w);
        int cnt=0;
        int len=strlen(w);
        for(int i=0;i<len&&cnt<nc;i++)//将没有出现的字符顺序编号
        {
            if(id[w[i]]!=-1) continue;
            id[w[i]]=cnt++;
        }
        int ans=0;
        for(int i=0;i<len-n+1;i++)//
        {
            int s=0;//s为长度为n的字符串的hash值
            for(int j=i;j<i+n;j++)
                s=s*nc+id[w[j]];//将s代替的长度为n字符串表示成nc进制的数
            if(hash[s]) continue;
            hash[s]=true;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
