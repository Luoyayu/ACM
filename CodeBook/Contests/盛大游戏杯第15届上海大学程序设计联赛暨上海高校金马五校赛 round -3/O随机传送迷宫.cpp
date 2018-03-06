#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 500000+55;
int a2[N];
int a[N];
int d[N];       //d[i] 长度为i的递增子序列的最小值
int d2[N];
int BinSearch(int key, int* d, int low, int high)
{
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(key>d[mid] && key<=d[mid+1])
            return mid;
        else if(key>d[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}

int LIS(int* a, int n, int* d)
{
    int i,j;
    d[1] = a[1];
    int len = 1;
    for(i = 2; i <= n; i++)
    {
        if(d[len]<a[i])
            j = ++len;
        else
            j = BinSearch(a[i],d,1,len) + 1;
        d[j] = a[i];
    }
    return len;
}
int main()
{
    int p;
    while(scanf("%d",&p)!=EOF)
    {
        memset(d,0,sizeof d);
        memset(d2,0,sizeof d2);
        for(int i = 1; i <= p; i++)
            scanf("%d",&a[i]),a2[i]=a[p-i+1];
        LIS(a,p,d);LIS(a2,p,d2);
        int MAX=-1;
        for(int i=1;i<=p;i++)

            if(d[i]==d2[p-i+1]-1)
                MAX=d[i];
        printf("%d\n",MAX);
    }

    return 0;
}
