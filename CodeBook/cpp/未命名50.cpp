#include<cstdio> 
#include<string.h>
#include<cctype>
const int N = 200000 + 10;
using namespace std; 
int node[N][26];        
int sz;                 
int val[N];      
void init()  
{  
    sz=1;  
    memset(node[0],0,sizeof(node[0]));  
    memset(val,0,sizeof(val));  
}  
void insert(char *str)  
{  
    int u=0,c;  
    for(int i=0;i<strlen(str);i++)  
    {  
        c=str[i]-'a';  
        if(!node[u][c])  
            node[u][c]=sz++;  
        u=node[u][c];  
        val[u]++;          
    }  
}  
int query(char *str)  
{  
    int u=0,c;  
    for(int i=0;i<strlen(str);i++)  
    {  
        c=str[i]-'a';  
        if(!node[u][c])  
            return 0;  
        u=node[u][c];  
    }  
    return  val[u];  
}  
int main(){  
    int i;  
    char str[20];  
    init();  
    while(1)
	{  
        gets(str);  
        if(str[0]=='\0')break;  
        insert(str);  
    }  
    while(scanf("%s",str)!=EOF){  
        printf("%d\n",query(str));  
    }  
    return 0;  
}  