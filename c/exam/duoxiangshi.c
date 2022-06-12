#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int coef;  //系数
    int expn;  //指数
    struct Node *next;
}Node;

Node* create()
{
    	Node *head=NULL,*p=NULL;
    	int x,i;
    	scanf("%d",&x);
    	for(i=0;i<x/2;i++) 
    	{
    		if(head == NULL)
    		{
    			head=(Node *)malloc(sizeof(Node));
    			scanf("%d%d",&head->coef,&head->expn);
    			p=head;
    		}
    		else
    		{
    			p->next=(Node *)malloc(sizeof(Node));
    			p=p->next;
    			scanf("%d%d",&p->coef,&p->expn);
    		}
    	} 
    	p->next = NULL;
    	return head; 
}
Node* add(Node *a,Node *b)
{
	Node *tail,*p;
	if(a->expn < b->expn)
	{
		tail = a;
		a = b;
		b = tail;
	}
	p = a;
	tail = p;
	while(a != NULL && b != NULL)
	{
		while((a !=NULL) && (a->expn > b->expn))
		{
			tail = a;
			a = a->next;
		}
		if(a != NULL)
		{
			if(a->expn == b->expn)
			{
				a->coef += b->coef;
			}
			else
			{
				tail->next = (Node *)malloc(sizeof(Node));
				tail = tail->next;
				tail->coef = b->coef;
				tail->expn = b->expn;
				tail->next = a;
			}
			b = b->next;
		}
	}
	if(b != NULL)
		tail->next = b;
	return p;
}
void print(Node *head)
{
    while(head != NULL)
    {
    	printf("%d %d ",head->coef,head->expn);
    	head=head->next;
    }
}

int main()
{
    Node *a,*b,*c;
    a = create();
	b = create();
	c = add(a,b);
    print(c);
    return 0;
}


