//扩展KMP/Manacher算法 回文串判定
//扩展KMP算法：应用与给定文本串S，模式串P，对于每个S[i]求出S[i...Slen-1]与T的最长公共前缀长度，将本串s1反转形成s2串
//记作extend[i]，如果S在某个位置i有entend[i]=m，则可知在S中好到了匹配串T，并且匹配的首位置为i,匹配了模式串extend[i]个位置
//如果extend[len-i]==i则前i个字符为回文串
#include<bits/stdc++.h>
using namespace std;
#define next NEXT
const int MAX=500000+10;
char s1[MAX],s2[MAX];
int Next1[MAX],ex1[MAX],ex2[MAX],next[MAX];
int sum[MAX],val[27];

void get_next(char *a,int len){
    int k=0,i=1;
    next[0]=len;//可有可无,因为用不上
    while(k+1<len && a[k] == a[k+1])++k;
    next[1]=k;//这里预先算好next[1]是因为不能k=0,否则next[i-k]=next[i]不是已算好的
    k=1;
    while(++i<len){//和EKMP的过程一样
        int maxr=k+next[k]-1;
        next[i]=min(next[i-k],max(maxr-i+1,0));
        while(i+next[i]<len && a[next[i]] == a[i+next[i]])++next[i];
        if(i+next[i]>k+next[k])k=i;
    }
}

void EKMP(char *a,char *b,int *extend,int len){
    get_next(a,len);
    int k=0,i=0;
    while(k<len && a[k] == b[k])++k;
    extend[0]=k;
    k=0;
    while(++i<len)
    {
        int maxr=k+extend[k]-1;
        extend[i]=min(next[i-k],max(maxr-i+1,0));//next[i-k]是a与b从i开始的可能已经匹配的长度
        while(i+extend[i]<len && a[extend[i]] == b[i+extend[i]])++extend[i];//这里是扩展KMP的精髓,即算法核心思想就是这
        if(i+extend[i]>k+extend[k])k=i;
    }
}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
    {
        memset(sum,0,sizeof sum);
		for(int i=0;i<26;++i)
            scanf("%d",&val[i]);
		scanf("%s",s1);
		int len=strlen(s1);
		for(int i=1;i<=len;++i)
		{
			sum[i]=sum[i-1]+val[s1[i-1]-'a'];
			s2[i-1]=s1[len-i];
		}
		EKMP(s1,s2,ex1,len);
		EKMP(s2,s1,ex2,len);
		#ifdef Local
		for(int i=0;i<strlen(s1);i++)
            printf("%d ",ex1[i]);
        printf("\n");

        for(int i=0;i<strlen(s2);i++)
            printf("%d ",ex2[i]);
        printf("\n");
        #endif // Local
		int ans=0,temp=0;
		for(int i=1;i<len;++i)
        {
			if(ex1[len-i] == i)temp+=sum[i];//表示前i个字符是回文串
			if(ex2[i] == len-i)temp+=sum[len]-sum[i];//表示后len-i个字符为回文串
			if(temp>ans)ans=temp;
			temp=0;
		}
		printf("%d\n",ans);

	}
	return 0;
}
