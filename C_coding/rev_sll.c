#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head,*temp,*newnode;
struct node* reverse(struct node*);
int main()
{
	int n,data;
	printf("Enter the num of nodes in a list\n");
	scanf("%d",&n);
	printf("Enter the datain head node\n");
	scanf("%d",&data);
	head=(struct node*)malloc(sizeof(struct node));
	head->data=data;
	head->next=NULL;
	temp=head;
	for(int i=1;i<=n-1;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data in to node %d\n",i);
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;

		temp->next=newnode;
		temp=newnode;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}

	printf("revrese\n");
	struct node*rev=reverse(head);
	temp=rev;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
		
	}	
}
struct node* reverse(struct node* head)
{

	struct node*prev,*current,*next;
	temp=head;
	prev=NULL;
	current=head;

	while(current!=NULL)
	{
		next=current=next;
		current->next=prev;

		prev=current;
		current=next;
	}
	head=prev;
	return head;

}
		

