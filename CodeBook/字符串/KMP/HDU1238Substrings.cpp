/* STL 做法
#include<bits/stdc++.h>
using namespace std;
string s[102];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        int len=9999,sub=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i].c_str());
            if(len>s[i].size())//找到最短的串
            {
                len=s[i].size();
                sub=i;
            }
        }
        int maxn=0;
        for(int i=len; i>0; i--)
            for(int j=0; j<len-i+1; j++)
            {
                string s1,s2;
                s2=s1=s[sub].substr(j,i);
                reverse(s2.begin(),s2.end());
                for(int k=0; k<n; k++)
                    if(s[k].find(s1,0)==-1&&s[k].find(s2,0)==-1)
                        break;
                if(k==n && maxn<s1.size())
                    maxn=s1.size();
            }
        printf("%d\n",maxn);
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
char str[102][102];
int kmpnext[102];
void getnext(char *x, int len) {
    int j = kmpnext[0] = -1, i = 0;
    while (i < len) {
        while (j != -1 && x[i] != x[j]) j = kmpnext[j];
        if (x[++i] == x[++j])
            kmpnext[i] = kmpnext[j];
        else
            kmpnext[i] = j;
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int len = 111, index = 0;
        for (int i = 0; i < n; i++)  //找到最短串及其序号
        {
            scanf("%s", str[i]);
            int tmplen = strlen(str[i]);
            if (len > tmplen) len = tmplen, index = i;
        }
    }
}