#include<iostream>
//暴力点-_-一开始想到了一篇数学文章讨论的关于ax+by+cz的最大表示数,YY了一会，啥(a,b,c)要等于1,算了暴力吧,简单点。
int a,b,c,n;
int f()
{
    int k = n/a+1;
    for(int i=0;i<k;i++)
        for(int j=0;;j++)
        {
            int h=n-i*a-j*b;
            if(h<0) break;
            if(h%c==0)return 1;
        }
  return 0;
}
main ()
{
    int t;std::cin>>t;
    while(t--)
    {
        std::cin>>a>>b>>c>>n;
        if(f())std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}
