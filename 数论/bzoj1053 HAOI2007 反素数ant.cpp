///�󲻳���N���������
///������x,Լ���ĸ���g(x),���������0<i<x,g(i)<g(x),xΪ��������
///����������:�϶���2��������ӣ������ʷֽ��С�������ݴ����Ȼ����������;
///����1~n�ڵ��������Ӹ��������ɣ����������ĳ����Լ�������Ǹ���
///˼·:ȡС��������,��Ȼǰ20��������˳˻�����20�ڣ�
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
ll ans,n;
const ll INF= 0x3f3f3f3f;
int best;
void dfs(int dep,ll tmp,int num)///num��¼���Ӹ���
{
    if(dep==16) return ;
    if(num>best)///update best
    {
        best=num;
        ans=tmp;
    }
    if(num==best) ans=min(tmp,ans);///��������ͬʱȡ��С��
    for(int i=1;i<=62;i++)//�ݹ����
    {
        if(n/prime[dep]<tmp) break;//��֦
        dfs(dep+1,tmp*=prime[dep],num*(i+1));
    }
}
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        ans=INF;
        best=0;
        dfs(0,1,1);
        printf("%lld\n",ans);
    }
    return 0;
}
