//��Ŀ̫����(((��(����;)��)))
//һ�������s����ϵͳ,����n��bug
//��һ��buֻ����һ����ϵͳ������һ������
//Ivanÿ�췢��һ��bug,���bug����ĳ����ϵͳ�ĸ�����1/s,����ĳ�������������1/n
//�ʷ���n��ug����ÿ����ϵͳ������bug������������
//״̬��dp[i][j]��ʾ�Ѿ��ҵ�i��bugs���ﵽĿ��״̬������������
//ת�Ʒ���:     dp[i][j]=(i/n)*(j/s)
//              dp[i][j+1]=(i/n)*(1-j/s)
//              dp[i+1][j]=(1-i/n)*(j/s)
//              dp[i+1][j+1]=(1-i/n)*(1-j/s)
//����ģ�dp[i][j]=
//�߽磺dp[n][s]=0
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000+10;
double dp[maxn][maxn];
int main()
{
    int n,s;
    while(scanf("%d %d",&n,&s)!=EOF)
    {
        memset(dp,0,sizeof dp);
        for(int i=n;i>=0;i--)
            for(int j=s;j>=0;j--)
                if(i==n&&j==s)
                    dp[i][j]=0;
                else
                    dp[i][j]=(i*(s-j)*dp[i][j+1]+(n-i)*j*dp[i+1][j]+(n-i)*(s-j)*dp[i+1][j+1]+n*s)/(n*s-i*j);
            printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}
