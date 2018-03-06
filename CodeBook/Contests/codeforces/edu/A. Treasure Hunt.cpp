#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,y1,y2;
    int a,b;
    //freopen("C:\\Users\\gavin\\Desktop\\input.txt",'r',stdin);
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
    {
        scanf("%d%d",&a,&b);
        int X=abs(x1-x2);
        int Y=abs(y1-y2);
        if((X/a)%2==(Y/b)%2&&X%a==0&&Y%b==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        x1=x2=y1=y2=a=b=X=Y=0;
    }
    return 0;
}
