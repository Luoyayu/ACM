#include<bits/stdc++.h>
//题意给出大数A,B,讲B插入A中,求最小的插入后的值
using namespace std;
const int maxn=100000+10;
int kmpnext[maxn],ex[maxn];
char s1[maxn],s2[maxn];
int exkmp()
{
    int i,j,p;
    int s1len=strlen(s1),s2len=strlen(s2);
    for(i=0,j=0,p=-1,s1<=s1len;i++,j++,p--)
    {
        if(p==-1)
        {
            j = 0;
            do
                p++;
            while(i+p<=s1len&&s1[i+p]==s2[j+p]);
            ex[i]=p;
        }
        else if(kmpnext[j]<p) ex[i]=kmpnext[j];
        else if(kmpnext[j]>p) ex[i]=p;
        else 
        {
            j=0;
            while(i+p<=s1len && s1[i+p]==s2[j+p])
                p++;
            ex[i]=p;
        }
    }
    ex[i]=0;
}
int main()
{

}