#include<bits/stdc++.h>
using namespace std;
bool isp[10000];
int retw(int year,int month,int day)
{
    if(month<=2)
        month+=12,year--;
    int res=(day+2*month+3*(month+1)/5+year+(year>>2)-year/100+year/400)%7;
    return res;
}

bool check(int n)
{
    if(n%400==0||n%4==0&&n%100)return 1;
    return 0;
}
void init()
{
    for(int i=1000;i<=9999;i++)
        isp[i]=check(i);
}
int main()
{
    int T;
    init();
    scanf("%d",&T);
    for(int cnt=1;cnt<=T;cnt++)
    {
        int year,month,day;scanf("%d-%d-%d",&year,&month,&day);
        int o=retw(year,month,day);

        if(month==2&&day==29) {
            for(int i=year+1;i<=9999;i++) {
                if(isp[i])
                    if(retw(i,month,day)==o) {
                        printf("%d\n",i);
                        break;
                    }
            }
        }
        else {
            for (int i = year + 1; i <= 9999; i++) {
                if (retw(i, month, day) == o) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
