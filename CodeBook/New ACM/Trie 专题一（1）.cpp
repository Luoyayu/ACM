#include <cstdio>
#include <cstring>
#include <cstdlib>
#define ul unsigned long
using namespace std;
//0/1 二叉树
struct node
{
    int cnt;
    node *next[2];//left and right child tree
    node()//init
    {
        cnt=0;
        for(int i=0;i<2;i++)
            next[i]=NULL;
    }
};
node *root, *p, *newnode;
int flag;
void insert(char *str)
{
	int index;
	ul len = strlen(str);
	p = root;
	for (int i = 0; i < len; i++)
	{
		index = str[i] - '0';
		if (p->next[index] != NULL)//节点存在
		{
			p = p->next[index];
			if (i == len - 1 || p->cnt == 1)
			{
				flag = 0;//means having prefix
				break;
			}
		}
		else
		{
			newnode = new node;//newcode is struct 
			p->next[index] = newnode; //构建子树
			p =p->next[index];//equal p=newnode;
		}
	}
	p->cnt = 1;//mark the end of word
} 
void del(node *head)
{
	for (int i = 0; i < 2; i++)
		if (head->next[i] != NULL)
			del(head->next[i]);
	delete (head);
}
int main()
{
	int kase = 1;
	char str[15];
	while (scanf("%s", str) != EOF)
	{
		flag = 1;//init
		root = new node;
		insert(str);
		while (scanf("%s", str), strcmp(str, "9"))
		{
			if (flag==0)
				continue;//waitting for end of scanf
			insert(str);
		}
		if (flag==0)
			printf("Set %d is not immediately decodable\n", kase++);
		else
			printf("Set %d is immediately decodable\n", kase++);
		del(root);
	}
	return 0;
}
