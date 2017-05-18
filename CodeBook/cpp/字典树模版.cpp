#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct Trie{
    int v;
    Trie *next[10];
};
Trie *root;
void createTrie(char *str)
{
    int len = strlen(str);
    Trie *p = root, *q;
    for(int i=0; str[i]!='\0'; ++i)
    {
        int id = str[i]-'0';
        if(p->next[id] == NULL)
        {
            q = new Trie;
            q->v = 1;
            for(int j=0; j<10; ++j)
                q->next[j] = NULL;
            p->next[id] = q;
        }
        else
            p->next[id]->v++;
        p = p->next[id];
    }
    p->v = -1;
}
 
int findTrie(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for(int i=0; i<len; ++i)
    {
        int id = str[i]-'0';
        p = p->next[id];
        if(p == NULL)
            return 0;
        if(p->v == -1)
            return -1;
    }
    return -1;
}
 
int deal(Trie* T)
{
    if(T==NULL)
        return 0;
    for(int i=0;i<10;i++)
        if(T->next[i]!=NULL)
            deal(T->next[i]);
    delete (T);
    return 0;
}
 
int main()
{
    char str[15];
    int T, n;
    bool flag;
    scanf("%d", &T);
    while(T--)
    {
        flag = 0;
        root = new Trie;
        for(int i=0; i<10; i++)
            root->next[i] = NULL;
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%s", str);
            if(findTrie(str) == -1)
                flag = 1;
            createTrie(str);
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
        deal(root);
    }
    return 0;
}