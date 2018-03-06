#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define debug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl;
typedef long long ll;
const int mod = 1e9+7;
//题意:求s2的所有后缀在s1中 sum(在s1出现的次数*该后缀的长度)
const int maxn = 1e6+7;
char s1[maxn],s2[maxn];
int ext[maxn], nxt[maxn];
//ex_kmp(s1,s2)求ex[i],s1的后缀与s2的最长公共前缀的长度
void getnext(char *T,int len)
{
    int i;
    nxt[0] = len;
    for(i = 0;i<len-1 && T[i]==T[i+1]; i++);
    nxt[1] = i;
    int a = 1;
    for(int k = 2; k < len; k++) {
        int p = a+nxt[a]-1, L = nxt[k-a];
        if( (k-1)+L >= p ) {
            int j = (p-k+1)>0? (p-k+1) : 0;
            while(k+j<len && T[k+j]==T[j]) j++;
            nxt[k] = j, a = k;
        }
        else nxt[k] = L;
    }
}
void getextand(char *S,char *T) {
    memset(nxt,0,sizeof(nxt));
    int Slen = strlen(S), Tlen = strlen(T), a = 0;
    getnext(T,Tlen);
    int MinLen = Slen>Tlen?Tlen:Slen;
    while(a<MinLen && S[a]==T[a]) a++;
    ext[0] = a, a = 0;
    for(int k = 1; k < Slen; k++) {
        int p = a+ext[a]-1, L = nxt[k-a];
        if( (k-1)+L >= p ) {
            int j = (p-k+1)>0? (p-k+1) : 0;
            while(k+j<Slen && j<Tlen && S[k+j]==T[j] ) j++;
            ext[k] = j;a = k;
        }
        else ext[k] = L;
    }
}

int main() {
    int t;scanf("%d",&t);
    while(t--) {
        scanf("%s%s",s1,s2);
        strrev(s1);strrev(s2);//同时反转s1,s2
        int len = strlen(s1);
        getextand(s1,s2);
        ll ans = 0;
        for(int i=0;i<len;i++){ //每一位对答案的贡献是1+2+···ex[i]
            ans = (ans+ 1LL*ext[i]*(1+ext[i])/2)%mod;
        }
        printf("%lld\n",ans);
    }
}

