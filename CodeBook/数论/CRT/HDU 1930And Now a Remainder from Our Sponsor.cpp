///加解密问题，妥善处理字符数字,注意去多个尾空白
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=2000+55;
int keyword[5],encoded[maxn];
int res[maxn],r[5];
int output[maxn];
int ex_gcd(int a,int b,int &x,int &y)
{
    if(!b){x=1;y=0;return a;}
    int ans=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ans;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    int ok=0;
    while(t--)
    {
        scanf("%d",&n);ok=1;

        for(int i=0;i<4;i++)
            scanf("%d",&keyword[i]);//存放余数
        for(int i=0;i<n;i++)
            scanf("%d",&encoded[i]);//存放余数

        for(int i=0;i<n;i++)//求解同余方程组可用CRT的非互质版本，合并上升同余方程
        {
            //x==ri(mod mi)//构建4个同余方程的同余方程组
            r[0]=encoded[i]/1000000;//提取余数
            r[1]=(encoded[i]%1000000)/10000;
            r[2]=encoded[i]%10000/100;
            r[3]=encoded[i]%100;

            int m1=keyword[0],r1=r[0];

            for(int j=1;j<4;j++)//CRT2
            {
                int x,y;
                int m2=keyword[j],r2=r[j];
                int d=ex_gcd(m1,m2,x,y);
                int c=r2-r1;
                int tmp=m2/d;
                x=(c/d*x%tmp+tmp)%tmp;
                r1=x*m1+r1;///最小正解r1
                m1=m1/d*m2;///mods LCM m1
            }
            res[i]=r1;
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int a=res[i]/10000;//翻译密码
            int b=res[i]%10000/100;
            int c=res[i]%100;
            if(a!=27)
                output[cnt++]='A'+a-1;
            else
                output[cnt++]=' ';

            if(b!=27)
                output[cnt++]='A'+b-1;
            else
                output[cnt++]=' ';

            if(c!=27)
                output[cnt++]='A'+c-1;
            else
                output[cnt++]=' ';
        }
        while(output[cnt-1]==' ')//处理后面有多个空白的情况。。惨第一次没考虑到
            cnt--;
        for(int i=0;i<cnt;i++)
            printf("%c",output[i]);
        printf("\n");
    }
    return 0;
}
