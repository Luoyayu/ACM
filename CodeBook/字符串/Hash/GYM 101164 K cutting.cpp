/*
#include <bits/stdc++.h>
using namespace std;
string s1,s2;
struct node
{
    int h1,h2,h3;
    unsigned i,j;
    node(){}
    node(int h1,int h2,int h3, unsigned  i, unsigned j):h1(h1),h2(h2),h3(h3),i(i),j(j){}

    bool operator ==(const node b)
    {
        return (h1==b.h1 && h2 ==b.h2 && h3 ==b.h3);
    }
}H1[100000],H2[100000];
unsigned int BKDRHash(string str)
{
    unsigned int seed = 131;
    unsigned int hashs = 0;
    int len=str.size();
    for(int i=0;i<len;i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i] = char( ::tolower(str[i]));
        hashs = hashs * seed + (str[i]);
    }
    return (hashs & 0x7FFFFFFF);
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>s1>>s2)
    {
        unsigned int lens1 = s1.size();
        unsigned int lens2 = s2.size();
        int hs1[]={0,0,0}, hs2[]={0,0,0};
        int cnth1 = 0,cnth2 = 0;
        for(unsigned int i=1;i<=lens2-2;i++)
        {
            for(unsigned int j = 1 ;j+i<=lens1-1;j++)
            {
                hs2[0]=BKDRHash(s2.substr(0,i));
                hs2[1]=BKDRHash(s2.substr(i,j));
                hs2[2]=BKDRHash(s2.substr(j+i,lens2-(i+j)));
                sort(hs2,hs2+3);

                H2[cnth2++]=node(hs2[0],hs2[1],hs2[2],i,j);
                hs1[0]=BKDRHash(s1.substr(0,i));
                hs1[1]=BKDRHash(s1.substr(i,j));
                hs1[2]=BKDRHash(s1.substr(j+i,lens1-(j+i)));
                sort(hs1,hs1+3);
                H1[cnth1++]=node( hs1[0],hs1[1],hs1[2],i,j);
            }
        }

        for(int i=0;i<cnth1;i++)
        {
            for(int j=0;j<cnth2;j++)
            {
                if(H1[i]==H2[j])
                {
                    printf("YES\n");
                    string a1=s2.substr(0,H2[j].i),a2=s2.substr(H2[j].i,H2[j].j),
                    a3=s2.substr(H2[j].j+H2[j].i,lens2-(H2[j].i+H2[j].j));
                    string new2=a1+a2+a3;
                    string new1=s1;

                    transform(new2.begin(),new2.end(),new2.begin(),::tolower);
                    transform(new1.begin(),new1.end(),new1.begin(),::tolower);


                    if(new2==new1)
                    {
                        cout<<a1<<endl<<a2<<endl<<a3<<endl;
                        return 0;
                    }
                    new2 = a1+a3+a2;
                    transform(new2.begin(),new2.end(),new2.begin(), ::tolower);
                    if(new2==new1)
                    {
                        cout<<a1<<endl<<a3<<endl<<a2<<endl;
                        return 0;
                    }
                    new2 = a2+a1+a3;
                    transform(new2.begin(),new2.end(),new2.begin(), ::tolower);
                    if(new2==new1)
                    {
                        cout<<a2<<endl<<a1<<endl<<a3<<endl;
                        return 0;
                    }
                    new2 = a2+a3+a1;
                    transform(new2.begin(),new2.end(),new2.begin(), ::tolower);
                    if(new2==new1)
                    {
                        cout<<a2<<endl<<a3<<endl<<a1<<endl;
                        return 0;
                    }
                    new2=a3+a1+a2;
                    transform(new2.begin(),new2.end(),new2.begin(), ::tolower);
                    if(new2==new1)
                    {
                        cout<<a3<<endl<<a1<<endl<<a2<<endl;
                        return 0;
                    }
                    new2=a3+a2+a1;
                    transform(new2.begin(),new2.end(),new2.begin(), ::tolower);
                    if(new2==new1)
                    {
                        cout<<a3<<endl<<a2<<endl<<a1<<endl;
                        return 0;
                    }
                }
            }
        }
        printf("NO\n");
        return 0;
    }
}*/
