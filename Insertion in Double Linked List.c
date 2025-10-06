#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

void list(int n);
void printlist(struct node *head);
void addbeg(struct node *head);
void addend(struct node *head);
void addpos(struct node *head);

int main(){
	int n;
	printf("Enter the number of elements you want: ");
	scanf("%d",&n);
	list(n);
	return 0;
}

void list(int n){
	int data,i;
	struct node *newnode,*head,*temp,*bnode,*enode,*pnode;
	if(n<=0){
		printf("Invalid number of nodes.\n");
		return;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Unable to allocate memory.\n");
		return;
	}
	printf("Enter data for node 1: ");
	scanf("%d",&data);
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	head=newnode;
	temp=head;

	for(i=2;i<=n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==NULL){
			printf("Unable to allocate memory.\n");
			break;
		}
		printf("Enter data for node %d: ",i);
		scanf("%d",&data);
		newnode->data=data;
		newnode->prev=temp;
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
	printf("\nData in the linked list:\n");
	printlist(head);

	addbeg(head);
	addend(head);
	addpos(head);
}

void addbeg(struct node *head){
	struct node *bnode;
	int c,data;
	printf("\nDo you want to add a new node at the beginning?(1/0):");
	scanf("%d",&c);
	if(c==1){
		bnode=(struct node*)malloc(sizeof(struct node));
		if(bnode==NULL){
			printf("Unable to allocate memory.\n");
			return;
		}
		printf("Enter data for the node at the beginning:");
		scanf("%d",&data);
		bnode->data=data;
		bnode->prev=NULL;
		bnode->next=head;
		if(head!=NULL)
			head->prev=bnode;
		head=bnode;
		printf("\nLinked List after insertion at the beginning:\n");
		printlist(head);
	}else{
		printf("No insertion at beginning.\n");
	}
}

void addend(struct node *head){
	struct node *enode,*temp;
	int z,data;
	printf("\nDo you want to add a new node at the end?(1/0):");
	scanf("%d",&z);
	if(z==1){
		enode=(struct node*)malloc(sizeof(struct node));
		if(enode==NULL){
			printf("Unable to allocate memory.\n");
			return;
		}
		printf("Enter data for the node at the end:");
		scanf("%d",&data);
		enode->data=data;
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=enode;
		enode->prev=temp;
		enode->next=NULL;
		printf("\nLinked list after insertion at the end:\n");
		printlist(head);
	}else{
		printf("No insertion at end.\n");
	}
}

void addpos(struct node *head){
	struct node *pnode,*temp;
	int b,pos,data,i;
	printf("\nDo you want to insert a node at any position?(1/0): ");
	scanf("%d",&b);
	if(b==1){
		printf("Enter position to insert: ");
		scanf("%d",&pos);
		if(pos<1){
			printf("Invalid position.\n");
			return;
		}
		pnode=(struct node*)malloc(sizeof(struct node));
		if(pnode==NULL){
			printf("Unable to allocate memory.\n");
			return;
		}
		printf("Enter data for new node: ");
		scanf("%d",&data);
		pnode->data=data;
		if(pos==1){
			pnode->next=head;
			pnode->prev=NULL;
			if(head!=NULL)
				head->prev=pnode;
			head=pnode;
		}else{
			temp=head;
			for(i=1;i<pos-1 && temp->next!=NULL;i++)
				temp=temp->next;
			pnode->next=temp->next;
			pnode->prev=temp;
			if(temp->next!=NULL)
				temp->next->prev=pnode;
			temp->next=pnode;
		}
		printf("\nLinked list after insertion at position %d:\n",pos);
		printlist(head);
	}else{
		printf("No insertion at position.\n");
	}
}

void printlist(struct node *head){
	struct node *temp;
	if(head==NULL){
		printf("List is empty.\n");
		return;
	}
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

