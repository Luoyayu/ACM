#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
char str[1000000];
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
