#include<cstdio>
//注意使用unsinged int
using namespace std;
unsigned int n;
int main()
{
    while(scanf("%u",&n)!=EOF)
        printf("%u\n",((n << 16) | (n >> 16)));
    return 0;
}
