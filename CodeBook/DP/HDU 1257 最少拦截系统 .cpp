// 最少拦截系统
//最小递减子序列个数(可不连续) HDU 1257
//8
//17 16 15 16 13 12 14 12
//2 (17 16 15 13 12\ 16 14 12)

//8 
//389 207 155 300 299 170 158 65
//2 (389 300 299 170 158 65\ 207 155 )
#include<bits/stdc++.h>
using namespace std;
int dp[1005];//dp[i]代表第i个最长递减序列中当前状态的所含元素最小值 
int main()
{
    int n,j;
    while(scanf("%d",&n)!=EOF, n)
    {
        memset(dp,0,sizeof dp);
        int num=0; //num代表最长递减序列个数   
        while(n--)
        {   
            int x,j; 
            scanf("%d",&x);
            //将当前状态值与之前阶段值对比
            for(j=1;j<=num;j++) 
            {
                //如果比某个历史阶段的值小，则覆盖，读取下一状态值 
                if(x<=dp[j])
                {
                    dp[j]=x;
                    break;
                }
            }  
            //如果当前状态值比之前阶段值都大，则新增序列
            //新增的序列最小元素值为当前状态值   
            if(j>num)
                dp[++num]=x;
        }
        printf("%d\n",num);
    }
    return 0;
}