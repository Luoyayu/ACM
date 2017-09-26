//Questionnaire
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
int main(int argc, char const *argv[])
{
    int t;scanf("%d\n", &t);
    while(t--)
    {
        int a = 0
        int n;scanf("%d\n", &n);
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            if(x&1) a++;
            else a--;
        }
        if(a>=0) printf("2 1\n");
        else printf("2 0\n");
    }
    return 0;
}
