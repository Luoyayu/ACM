//杂题 与栈相关的括号匹配
//求最少操作数使得只含有'{','}'的字符串稳定
//定义稳定为空串或者S是稳定的{S}也是稳定的或者
//S,T是稳定的sT也是稳定的
//即规定稳定是 {}, {}{}, {{}{}}
//操作是'{'变成'}',或者'}'变成'{';
//先将所有{}配对从字符串中剔去然后剩下的从左自右两项相等+1不等+2 
#include<bits/stdc++.h>
using namespace std;
int ans;
string s, s2;
int main()
{
    ios::sync_with_stdio(false);
    int kase=1;
    while(cin>>s && s [0]!='-') //一个'-'或多个'-'
    {
        stack<char> stk;
        s2=""; ans = 0;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='{') stk.push('{');
            else if(stk.empty() && s[i]=='}') //只有队列空才放进右括号
                stk.push('}');
            else if(!stk.empty() && stk.top()=='}' && s[i]=='}')
                stk.push('}');
            else if(!stk.empty() && stk.top()=='{' && s[i]=='}')
                stk.pop();
        }
        while(!stk.empty())
        {
            s2+=stk.top();
            stk.pop();
        }
        len = s2.length();
        for(int i=0;i<len;i+=2)
            if(s2[i]==s2[i+1]) ans++;
            else ans += 2;

        printf("%d. %d\n",kase++,ans);
    }
    return 0;
}

/*

}{
{}{}{}
{{{}
---

1. 2
2. 0
3. 1

*/