#include<bits/stdc++.h>
const int maxn = 1e6+7;
char str[MAXN];
using namespace std;
int main()
{
        map<string,string>dic;
        string a,b;
        cin >> a;
        while( (cin >> a) && a != "END")
        {
            cin>>b;
            dic[b]=a;
        }
        cin>>a;
        getchar();
        while(gets(str)!=NULL)
        {
            if(!strcmp(str,"END")) break;
            a="";
            for(int i=0;str[i]!='\0';i++)
            {
                char c = str[i];
                if(isalpha(c)) 
					a += c;
                else 
					if(a!="")
                    {
                        if(dic[a]!="")
                        	cout<<dic[a];
                        else
					 		cout<<a;
                        a="";
                        cout<<c;
                    }
					else 
						cout<<c;
            }
            printf("\n");
        }
        return 0;
}
