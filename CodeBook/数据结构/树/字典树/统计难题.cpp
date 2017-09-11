#include <cstdio>
#include <cstring>
#define maxn 28
using namespace std;
struct node
{
	int cnt;
	node *next[maxn];
	node()
	{
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
};
node *root = new node,*p;
void insert(char *str)
{
	p = root;
	for (int i = 0; str[i]; i++)
	{
		int id = str[i] - 'a';
		if (p->next[id] == NULL)
			p->next[id] = new node;//not[ new node(); ]
		p = p->next[id];
		p->cnt++;
	}
}
int find(char *str)
{
	p = root;
	for (int i = 0; str[i]!='\0'; i++)
	{
		int id = str[i] - 'a';
		if (p->next[id] == NULL)
			return 0;
		p = p->next[id];
	}
	return p->cnt;
}
int main()
{
	char str[15];
	root = new node;
 	while (gets(str)&&str[0]!=NULL)  
 		insert(str);  
    while (gets(str) != NULL)  
        printf("%d\n", find(str));  
    return 0;  
}
