
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int hh,mm;
    while(scanf("%d:%d",&hh,&mm)!=EOF)
    {
        if(hh==mm/10+mm%10*10)
        {
            cout<<"0"<<endl;
            return 0;
        }
        int HUI2=mm/10+mm%10*10;
        int HUI1=hh/10+hh%10*10;
        int HUI3=(hh+1)/10+(hh+1)%10*10;
        if(HUI1>=mm)
        {
            cout<<HUI1-mm<<endl;
            return 0;
        }
        if(hh==23&&mm>=32)
        {
            cout<<60-mm<<endl;
            return 0;
        }
        cout<<60-mm+HUI3<<endl;
        return 0;
    }

}
