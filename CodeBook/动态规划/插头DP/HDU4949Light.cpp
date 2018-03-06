//插头DP第一弹
//题意:给出n*m op1:反转cell(i,j) 相邻的四盏灯,op2: 反转cell(i,j)及其相邻的四盏灯
//求最少步骤关灯
//三进制列举影响 假设处理到(i,j)位 三进制前j-1位表示前i行的状态,后m-j+1表示第i-1行从j开始到最右端的状态
//三进制数的状态定义:0表示对于这个格子未进行过操作处于关着的状态,1表示这个格子进行了一次操作处于关着的状态，2表示这个格子未进行操作处于开着的状态。对于op1&op2 
//dp[i][j]表示在处理到第i个格子时,与该格子相关的其他格子处于j状态所需的最少的操作数。对于每个格子操作奇数次相当于操作一次,操作非零偶数次相当于操作2次。
//+滚动数组 时间复杂度O(n*m*3^m)
#include<cstdio>
using namespace std;
int len[15];//store 3^i
int dp[2][60000];
char word[11][11];
inline void init()
{
    len[0]=1;
    for(int i=1;i<=14;i++)
        len[i]=len[i-1]*3;
}

inline int gmin(int &a,int b) 
{
    a>b?a=b:0;
}


int main()
{

}


