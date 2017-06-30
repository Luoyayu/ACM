//Impartial Combinatorial Games(ICG) 无合法移动的玩家告负 
//P point: the postion Previous Player will win (抵达此点的选手负,既上次移动的选手必胜的点，后手必胜,为必败点)  
//N point: the postion Next Player will win (现在轮到move的人有必胜的策略,先手必胜,为必胜点)
//游戏分类：
//ICG: ending postion is N point Game 
//CG: ending postion is P point Game
//N-P点结论 1:无法移动的局面是P(必败)点, 2:可达P(必败)点的是N(必胜)点, 3:必达N(必胜)点的是P(必败)点
//博弈论（一）: Nim游戏 一个局面是P点(必败) 当且仅当a1^a2^a3...^an=0
bool Nim_game(int p[], int n)//对于n不是特别大O(n)算法
{
    int flag=0;
    for(int i=0;i<n;i++)
        flag ^= p[i];
    if(flag)
        return 1;//是N局面既初始必胜
    return 0;//初始为P局面既初始必败
}

//博弈论(二)：Bash Game 一堆石子,每次取[1,m]个,取完获胜
//分析可知:n=0为必败点               (1)
//0<n<=m 为必胜点 可达(1)            (2) 
//n=m+1  为必败点 必达到(2)          (3)
//m+1<=n<=m+1+m 为必胜点 可达(3)     (4)
//n=(m+1)+m+1为必败点 必达(4)        (5)
//可知 当 n=(m+1) 的整数倍 只能取到必胜点故此点为必败点
//既n=r*(m+1)+s 当s==0先手必败