#include <cstdio>
using namespace std;
//本题充分发挥了自造坑的最高水平,硬是自己挖了5个坑!警戒模拟！
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
            printf("No\n");
            continue;
        }

        if(bob>21)
        {
            printf("Yes\n");
            continue;
        }

        for(int i=4;i<=n;i++)
        {
            int alicein = alice;
            int bobin = bob;
            int fffffff = 0;//坑啊
            for(int k=5;k<=i;k++)
                if(alicein+a[k]>21)
                {
                    fffffff = 1；
                    i--;//泪目-_-
                    alicein = alice;
                    break;
                }
                else alicein += a[k];

            for(int j=i+1;j<=n;j++)//背包？题意？
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