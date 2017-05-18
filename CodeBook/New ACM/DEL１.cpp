int ch[200010][27];  //节点编号     
int sz;        //字典树节点个数  
int val[200010];   //节点的值  
void init()  
{  
    sz=1;  
    memset(ch,0,sizeof(ch));  
    memset(val,0,sizeof(val));  
}  
void insert(char *s)  
{  
    int u=0,c;  
    for(int i=0;i<strlen(s);i++)  
    {  
        c=s[i]-'a';  
        if(!ch[u][c])  
            ch[u][c]=sz++;  
        u=ch[u][c];  
        val[u]++;        //！！！  
    }  
}  
int query(char *s)  
{  
    int u=0,c;  
    for(int i=0;i<strlen(s);i++)  
    {  
        c=s[i]-'a';  
        if(!ch[u][c])  
            return 0;  
        u=ch[u][c];  
    }  
    return  val[u];  
}  