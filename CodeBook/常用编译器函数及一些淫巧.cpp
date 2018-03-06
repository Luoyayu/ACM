1. #include<bits/stdc++.h> 万能头文件 g++编译器自带
2. fmod(float,float) return 浮点数模运算
3. hypot(float,float) return 直角三角形斜边长 用于代替求两点距离
4. __builtin_popcount (unsigned) 返回二进制中1的个数
5. __gcd(int,int) 直接返回两个整形的gcd
6. #define Debug(x) cout<<#x<<"= "<<x<<endl; //中间过程调试  x不能过于复杂
7. lower_bound([__first,__last),__val) return 位置上的值不小于val的迭代器 //用于二分写
8. stl <utility>
   用法：1) pair<double,double> pl;
        2) pair<int,int> function_name()
           {
               return make_pair<double,double>;
           }
9.//行走江湖必备之读入挂
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
10.next_permutation()按字典序产生序列的下一个排列,三参数,排序起始,排序终点,可选排序范围个数
例如 num[]={1,2,3,4} next_permutation(num,num+4) 此时num={1,2,4,3} 
