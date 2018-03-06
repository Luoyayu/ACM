//MEX 求区间没有出现的最小负整数和 递推计数
//if a==0 mex(a,a)=1; else mex(a,a)=0; mex(set)=该集合中没有出现的最小非负数
//知if(b==b+1) mex(a,b)=mex(a,b+1)
//1,0,2,0,1
//mex(1,1)=0;mex(1,2)=2;mex(1,3)=3;mex(1,4)=3;mex(1,5)=3
//mex(2,2)=1;mex(2,3)=1;mex(2,4)=1;mex(2,5)=3
//mex(3,3)=0;mex(3,4)=1;mex(3,5)=3
//mex(4,4)=1;mex(4,5)=2
//mex(5,5)=0
//思路：以i结尾的所有区间和满足f[i]<=f[i+1]
//记第i个数为sa[i],后面出现的大于等于sa[i]的值会对f[i+1]产生影响,故有f[i]=f[i-1]+???
//如果j出现在1~i-1区间中，比较j最晚出现的位置与覆盖完全的1~j-1的最小位置的较小位置k，
//那么区间j的前一次出现的位置到k位置这个区间内所有点到i位置的值都+1.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[]="abc";
    char b[]="bbb";
    printf("%s",strcat(a,b));
}
