#include <bits/stdc++.h>
using namespace std;
const int maxn = 80000+77;
char A[maxn],B[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        scanf("%s %s",A, B);
        int notsame = 0;
        int MIN = min(a,b);
        for(int i=0;i<n;i++)
            if(A[i]!=B[i])
                notsame++;

        int same = n - notsame;
        if(MIN>=same)
            a-=same, b-=same;
        else
            a-=MIN, b-=MIN;

        if(notsame >= a+b)
            printf("Not lying\n");
        else
            printf("Lying\n");
    }
    return 0;
}

//过法二：
#include <bits/stdc++.h>
using namespace std;
const int maxn = 80000+77;
char A[maxn],B[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        scanf("%s %s",A, B);
        int notsame = 0;
        for(int i=0;i<n;i++)
            if(A[i]!=B[i])
                notsame++;
        int same = n - notsame;

       if(notsame >= abs(a-b) && (a+b)-same<=n )
            printf("Not lying\n");
        else
            printf("Lying\n");
    }
    return 0;
}