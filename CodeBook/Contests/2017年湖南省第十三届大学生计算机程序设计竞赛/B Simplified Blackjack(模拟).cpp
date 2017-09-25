#include <cstdio>
using namespace std;
//题意:首先alice,bob按顺序先摸4张牌,然后alice可以决定是否继续要牌,否则bob拿牌
//只要是alice在某次拿牌中取得的值大于，bob在之后的拿牌能取得的最大值,alice就能稳赢
//本题充分发挥了自造坑的最高水平,硬是自己挖了5个坑!警戒！
//前期拿到超过21点要预判下
int a[55];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),a[i]=a[i]>10?10:a[i];
        int alice = a[1] + a[3], bob = a[2] + a[4];
        bool flag = 0;

        if(alice>21)//坑死啊
        {
            printf("No\n");continue;
        }
        if(bob>21)
        {
            printf("Yes\n");continue;
        }

        for(int i=4;i<=n;i++)
        {
            int alicein = alice;
            int bobin = bob;
            int fffffff = 0;//坑啊 fffffff==1表示Alice拿到第i张拿不动了
            for(int k=5;k<=i;k++)//第5张可以不拿
                if(alicein+a[k]>21)
                {
                    fffffff = 1；
                    i--;//泪目-_-
                    alicein = alice;//还原上次点数
                    break;
                }
                else alicein += a[k];
            //Alice拿不动bob可以继续拿到最高点数比较
            for(int j=i+1;j<=n;j++)//题意
                if(bobin+a[j]>21) break;
                else bobin+=a[j];

            //printf("alocein = %d\n",alicein);
            //printf("Bobin = %d\n",bobin);

            if(alicein>bobin)
            {
                flag = 1;
                break;
            }
            if(fffffff)//全都是坑
            {
                flag = bool(alicein>bobin);
                break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}