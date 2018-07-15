#include<cstdio>
#include<cstring>
//xjb搞太菜
//思路:把原串0按1反转,记反转后为0串,
//用0串减原串得到新串,求这个新串的最长连续子串的最大值加上原串有的1的个数
using namespace std;
const int maxn = 1e5+7;
int a[maxn],b[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int SUM = 0;
        int sum=0,maxsum=-2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            SUM+=a[i];
            b[i]=a[i]==1?0:1;
            b[i]-=a[i];

            sum+=b[i];
            if(sum>maxsum) maxsum=sum;
            if(sum<0) sum=0;
        }
        int ans = SUM + maxsum;
        printf("%d\n",ans);
    }
    return 0;
}
