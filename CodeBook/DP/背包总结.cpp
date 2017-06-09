//那些年我们背过的包
//01背包 完全背包 多重背包 混合三种背包 二维费用背包 分组背包
//TODO: 多重背包 混合三种背包 二维费用背包 分组背包

//<**************  ZeroOnePack 01背包*****************>
//有N【件】物品和一个容量为 V的背包。(每种物品均只有一件)：费用c[i],价值w[i]。
//求解将哪些物品装入背包可使价值总和最大
//dp[i][v] 表示前i件物品恰放入一个容量为v的背包可获得的最大价值
转移方程:dp[i][v]=max(dp[i-1][v],dp[i-1][v-c[i]]+w[i])
//转移方程：将前i件物品放进容量为V的背包中的子问题, 若当前考虑第i件物品的策略(放或不放)，那么问题转换成
//一个只和前i-1个物品相关的问题。如果不放第i件物品,那么假设前i-1个物品已经最优,不放总价值就是dp[i-1][v];
//如果放那么问题就是前i-1件物品放入v-ci的背包中最大价值就是dp[i-1][v-c[i]+w[i]]
//空间优化: dp[v] 表示把前i件物品放进容量为V的背包取得的价值
if(恰好装满背包) dp[0]=0,clear(dp+1,-oo); 
if(不必装满) clear(dp,-oo);
//由前一个状态逆推，由当前状态决定正推
for(int i=1;i<=N;i++) //N件物品
    for(int v=V;v>=c[i];v--)
        dp[v]=max(dp[v],dp[v-c[i]]+w[i]);//每一次决策都去和上一步的最优状态比较


//<**************CompletePack*****************>
//有N【种】物品和一个容量为 V的背包(每种物品都有无限件)第i种费用是c[i]，价值是w[i]。
//求解将哪些物品装入背包可使这些物品的cost总和不超过V，且价值总和最大。
转移方程:dp[i][v]=max(dp[i-1][v-k*c[i]]+k*w[i]|0<=k*c[i]<=v)
//空间优化:
for(int i=1;i<=N;i++)
    for(int v=c[i];v<=V;v++)
        dp[v]=max(dp[v],dp[v-c[i]]+w[i]);

//<*************多重背包******************>



