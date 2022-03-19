#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

void createNode()
{
	struct node *newnode, *temp;
	int input;
	printf("Enter the data you want to enter in the LL: ");
	scanf("%d", &input);
	newnode = (struct node*)maloc(sizeof(struct node));
	newnode->data = input;
	
	if(head == NULL)
	{
		head = newnode;
		temp = newnode;
		newnode->next = NULL;
	}
	else
	{	
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		newnode->next = NULL;
	}
}

void insertBegin()
{
	struct node *newnode, *temp;
	int input;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
		printf("Overflow!\n");
	else
	{
		printf("Enter the data you want to enter in the LL: ");
		scanf("%d", &input);
		newnode->data = input;
		newnode->next = head;
		head = newnode;
	}
}

void insert()
{
	int index, input, i;
	struct node *newnode, *temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
		printf("Overflow!\n");
	else
	{
		printf("Enter the data you want to enter in the LL: ");
		scanf("%d", &input);	
		printf("Enter the location at which you want to enter a node: ");
		scanf("%d", &index);
		newnode->data = input;
		temp = head;
		for(i = 0 ; i < index ; i++)
		{
			temp = temp->next;
			if(temp == NULL)
			{
				printf("Cant insert!\n");
				return ;
			}
		}
		newnode->next = temp->next;
		temp->next = newnode;	
	}
}

int main()
{
}
