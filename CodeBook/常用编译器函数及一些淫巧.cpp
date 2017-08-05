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
9.//超级读入挂
        namespace IO
        {
            const int len=4e7;char buf[len];int sz,p;       //4e7大概大小为44M
            void begin(){p=0;sz=fread(buf,1,len,stdin);}
            inline bool read(LL &x)
            {
                if (p==sz)return 0;int f=1,d=0;char s=buf[p++];
                while(s<'0'||s>'9'&&p<sz){if(s=='-') f=-1;s=buf[p++];}
                while(s>='0'&&s<='9'&&p<sz){d=d*10+s-'0';s=buf[p++];}
                x=f*d; return p!=sz;
            }
            inline void writeln(LL x)
            {
                if(x==0){putchar('0');putchar('\n');return;}
                if(x<0)putchar('-'),x=-x;int len=0,buf[20];
                while(x)buf[len++]=x%10,x/=10;int i=len-1;
                while (i>=0){putchar(buf[i--]+'0');}putchar('\n');return;
            }
        }
    用法: IO::read(x); IO::writeln(x);

10.
