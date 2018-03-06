//Mine STL
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
struct Node
{
    int grade;
    Node* next;
};
FILE *fp=fopen("D:\\a.txt","w+");
int main()
{
    Node *head,*p,*pre;
    head=(struct Node*)malloc(sizeof(Node));
    head->next=NULL,pre=head;
    while(1)
    {	
		p=(struct Node*)malloc(sizeof(Node));
		scanf("%d",&p->grade);
		if(p->grade<=0) break;
			pre->next=p,pre=p,p->next=NULL;
    }
    
    while(1)
    {	
	    p=(struct Node*)malloc(sizeof(Node));
	    scanf("%d",&p->grade);
	    if(p->grade<=0) break;
			pre->next=p,pre=p,p->next=NULL;
    }
    
  	p=head->next;
 	
    while(p)
    {
        fprintf(fp,"%d\n",p->grade);
        p=p->next;
    }
  
  int n;
	scanf("%d",&n);
	Node *j;
	j= head->next;
	while (j)
	{
		if ( n== j->grade) {printf("����\n");break;}; //1��ʾ�ظ�Ӧ����ʾ
		j = j->next;
	}

    fclose(fp);
    
    
    return 0;
}
