//进化率问题 最终N-1 的物种数量  进化概率P(i,j) i->j
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=220;
struct matrix
{
    double mat[maxn][maxn];
};
double p[maxn];
matrix multi(matrix a,matrix b)
{
    matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(a.mat[i][j]==0) continue;
            for(int k=0;k<n;k++)
            {
                if(b.mat[j][k]==0) continue;
                c.mat[i][k]+=a.mat[i][j]*b.mat[j][k];
            }
        }
    return c;
}
matrix pow_matrix(matrix a,int B)
{
    matrix e;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            e.mat[i][j]=(i==j);

    while(B)
    {
        if(B&1)
            e=multi(e,a);
        B>>=1;
        a=multi(a,a);
    }
    return e;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        matrix e;//单位矩阵
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                e.mat[i][j]=(i==j);

        for(int i=0;i<n;i++)
            scanf("%lf",&p[i]);

        int t;scanf("%d",&t);

        while(t--)
        {
            int I,J;double P;
            scanf("%d%d%lf",&I,&J,&P);
            e.mat[I][J]+=P;
            e.mat[I][I]-=P;
        }

        e=pow_matrix(e,m);

        double ret=0;
        for(int i=0;i<n;i++)
        {
            ret+=p[i]*e.mat[i][n-1];
        }
        printf("%0.lf\n",ret);
    }
    return 0;
}

