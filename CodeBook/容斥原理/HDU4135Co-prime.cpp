///容斥原理初步
///给定A,B,N 问AB内有多少和N互质的数的个数
///求[1,m]与n互质的数的个数(m-cnt)或者不互质的个数 cnt 不互质的数一定是N的质因子的倍数
///A,B,N<=10^15
///当m=12,n=30时 质因子 2,3,5 (2,4,6,8,10,12):m/2个,(3,6,9,12):m/3个,(5,10):m/5个
///注意到12,10,6在多个质因子倍数中
///正确公式:m/2 + m/3 + m/5 - m/(2*3) - m/*(2*5) - m/(3*5) + m/(2*3*5)
///对于奇数个质因子相乘加号,对于偶数个质因子相乘减号 奇加偶减
///容斥实现：位运算，dfs, 队列数组
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n;
ll prime[555];
int cnt=0;
void prime_factor()
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime[cnt++]=i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1) prime[cnt++]=n;
    return ;
}
///容斥的位运算 假设返回cnt=3个质因子数,那么选和不选就有001,010,100,011,101,110,111既2^cnt-1中情况
///使用&判断某一位是否为1来表示是否选择该质因子
long long bit_op(ll m)
{
    ll ret=0;
    for(int i=1;i<(1<<cnt);i++)
    {
        int mulSum=1,tot=0;
        for(int j=0;j<cnt;j++)
        {
            if(i&(1<<j))
            {
                tot++;
                mulSum*=prime[j];
            }
        }
        if(tot&1) ret+=m/mulSum;
        else ret-=m/mulSum;
    }
    return ret;
}
///使用dfs容斥
int dfs()
{

}
int main()
{
    int t;scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        cnt=0;
        scanf("%d%d%d",&a,&b,&n);
        //cin>>a>>b>>n;
        prime_factor();
        ll det=bit_op(b)-bit_op(a-1);
        cout<<"Case #"<<kase<<": "<<b-a+1-det<<endl;
    }
    return 0;
}
