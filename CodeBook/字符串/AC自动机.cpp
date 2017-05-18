//<Trie+KMP+手工queue>实现的多模式串字符匹配算法——AC自动机(Aho-Corasick automation)
#include<bits/stdc++.h>
using namespace std;
const int _size=26;
const int kind = _size;
struct node
{
    node *failure;       //失配指针
    node *next[kind]; //Tire每个节点的个子节点（最多个字母）
    int count;        //是否为该单词的最后一个节点
    node()
    {
        failure=NULL;
        count=0;
        memset(next,NULL,sizeof(next));
    }
}*q[500001];          //队列，方便用于bfs构造失配指针
char word[51];     //输入的单词
char T[1000001];    //模式串
int head,tail;        //队列的头尾指针

void createTree(char *str,node *root)//建trie树
{
    node *p=root;
    int i=0,index;
    while(str[i])
    {
        index=str[i]-'a';
        if(p->next[index]==NULL)
            p->next[index]=new node;
        p=p->next[index];
        i++;
    }
    p->count++;     //单词的最后一个节点count+1，代表一个单词
 }
 void build_ac_automation(node *root)//失配指针
 {
    int i;
    root->fail=NULL;
    q[head++]=root;
    while(head!=tail)
    {
        node *temp=q[tail++];
        node *p=NULL;
        for(i=0;i<_size;i++)
        {
            if(temp->next[i]!=NULL)
            {
                if(temp==root)
                    temp->next[i]->fail=root;
                else
                {
                    p=temp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) temp->next[i]->fail=root;
                }
                q[head++]=temp->next[i];
            }
        }
    }
}
int query(node *root)//查询
{
    int i=0,cnt=0,index,len=strlen(str);
    node *p=root;
    while(str[i])
    {
        index=str[i]-'a';
        while(p->next[index]==NULL && p!=root)
            p=p->fail;
        p=p->next[index];
        p=(p==NULL)?root:p;
        node *temp=p;
        while(temp!=root && temp->count!=-1)
        {
            cnt+=temp->count;
            emp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}
int main()
{
    return 0;
}
