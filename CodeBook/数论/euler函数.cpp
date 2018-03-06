#include<bits/stdc++.h>
const int maxn=3000000+33;
using namespace std;
//欧拉函数 phi(n) 定义为比n小且与n互质的数的个数
//1.对n质分解n=p1^k1*p2^k2···pn^kn (可以通过筛掉质因子的倍数得出phi,但是在减的时候要使用容斥定理防止重复删减)
//2.可以推出的公式：phi(n)=n*(1-1/p1)*(1-1/p2)···(1-1/pn)
//证明:当n为素数时易得phi(n)=p(n^1)=n-1;
//当n为素数p的k次方,既n=p^k时,由公式得phi(n)=p^k-p^(k-1)需要容斥定理算了不证了

///<**************筛法***************>
int euler_phi(int n)//欧拉函数 复杂度 O(√n)
{
    int m=(int)sqrt(n+0.5);//只用到√n筛质因子
    int ans=n;
    for(int i=2;i<=m;i++)
        if(n%i==0)//第一次找到必为质因子
        {
            ans=ans/i*(i-1);//先除i防止中间溢出
            do n/=i;  //把该数的因子全部筛掉
            while(n%i==0);
        }
    if(n>1) ans=ans/n*(n-1);//防止还有一个质因子
    return ans;
}



///<*************欧拉表**************>
int phi[maxn];
int Euler[maxn]={0};
void phi_table(int n)//筛法欧拉表
{
    phi[1]=1;
    for(int i=2;i<=n;i++) if(!phi[i])
        for(int j=i;j<=n;j+=i)
        {
            if(!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}


///<*************递推欧拉**************>

///<*************递推欧拉**************>

//Euler函数的积性
//积性函数可以通过分解质因法和线筛法快速求得


