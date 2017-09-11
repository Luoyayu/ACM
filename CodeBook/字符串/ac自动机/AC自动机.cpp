//是时候学习Aho-Corasick automaton（多模匹配算法）了
//多个模式串字符串在原串中出现(多组KMP暴力)
//简单来说ac自动机等同于kmp的理解,key在建立失配指针,按失配指针遇到失配时规律跳转。
#include <bits/stdc++.h>
using namespace std;
//ac 自动机 trie数组实现
const int maxn = 10000;
#define Sigmasize (26)
int tot, son[maxn][Sigmasize], id[maxn], fail[maxn], q[maxn];
//son[][26] trie树; fai 失配指针
//id[x] = p 表示第p个模式串
int n;char s[maxn];
void insert(int p, int len)//build trie
{
    for(int dep=0,i=0,w;i<len;i++)
    {
        if(!son[dep][w=s[i]-'a']) son[dep][w]=++tot;
        dep=son[dep][w];//字典树层数
        if(i==l-1) id[dep]=p;//到达最后一层时,该 id[该层]=序号
    }
}
//fail指针的理解：每个节点的失配指针指向的是 以当前节点表示的为最后一个字符的最长当前字符串的后缀的字符串的 最后一个节点。
//例如有模式串 {abcd bce cd} first_c-> second_c -> third_c
//每个与根相连的字符的失配指针指向根
//失配指针的用处：比如上例有文本串abce 在d(abcd)发生失配时由d前一字符c跳转到c(bce)节点继续比较e(abcd)==e(bce)完成匹配输出

void make()
{
    int h=1, t=0, x;fail[0] = -1;
    for(int i=0;i<Sigmasize;i++) if(son[0][i]) q[++t] = son[0][i];
    while(h<=t) for(x=q[h++],i=0;i<26;i++)
        if(son[x][i]) fail[son[x][i]]=son[fail[x][i]],q[++t]=son[x][i];
        else son[x][i] = son[fail[x]][i];
}

void find(int len)
{
    for(int x=0,i=0,w;i<len;i++)
    {
        x = son[x][w=s[i]-'a'];
        for(int j=x;j;j=fail[j]) if(id[j]) printf("%d ",id[j]);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",s),insert(i,strlen(s));//输入多模式串
    while(1) scanf("%s",s),find(strlen(s)),puts("");//输入原串
    return 0;
}