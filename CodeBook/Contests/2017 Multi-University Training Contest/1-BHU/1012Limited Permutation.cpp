//超级读入挂
##include <bits/stdc++.h>
using namespace std;
namespace IO
{  
    const int len=4e7;char buf[len];int sz,p;
    void begin(){p=0;sz=fread(buf,1,len,stdin);}
    inline bool read(LL &x)
    {
        if (p==sz)return 0;int f=1,d=0;char s=buf[p++];
        while(s<'0'||s>'9'&&p<sz){if(s=='-') f=-1;s=buf[p++];}
        while(s>='0'&&s<='9'&&p<sz){d=d*10+s-'0';s=buf[p++];}
        x=f*d; return p!=sz;
    }
    inline void writeln(LL x)
    {
        if(x==0){putchar('0');putchar('\n');return;}
        if(x<0)putchar('-'),x=-x;int len=0,buf[20];
        while(x)buf[len++]=x%10,x/=10;int i=len-1;
        while (i>=0){putchar(buf[i--]+'0');}putchar('\n');return;
    }
}
int main(int argc, char const *argv[]) {
    int n;
    while(IO::read(n))
    {

    }
    return 0;
}
