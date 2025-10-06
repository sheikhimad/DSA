#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void list(int n);
void printlist(struct node *head);
void delbeg(struct node *head);
void delend(struct node *head);
void delpos(struct node *head);

int main(){
	int n;
	printf("Enter the number of elements you want: ");
	scanf("%d",&n);
	list(n);
	return 0;
}

void list(int n){
	int data,i;
	struct node *newnode,*temp,*head;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	head=newnode;
	temp=newnode;

	for(i=2;i<=n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==NULL){
			printf("Unable to allocate memory");
		}else{
			printf("\nEnter data: ");
			scanf("%d",&data);
			newnode->data=data;
			newnode->next=NULL;
			temp->next=newnode;
			temp=newnode;
		}
	}

	printf("\nThe elements of Linked List are: ");
	printlist(head);

	int c;
	printf("\nDo you want to delete at beginning?(1/0): ");
	scanf("%d",&c);
	if(c==1){
		head=head->next;
		printf("After deletion at beginning: ");
		printlist(head);
	}

	int x;
	printf("\nDo you want to delete at end?(1/0): ");
	scanf("%d",&x);
	if(x==1){
		struct node *prev=NULL;
		temp=head;
		while(temp->next!=NULL){
			prev=temp;
			temp=temp->next;
		}
		if(prev==NULL){
			free(head);
			head=NULL;
		}else{
			prev->next=NULL;
			free(temp);
		}
		printf("After deletion at end: ");
		printlist(head);
	}

	int z,pos;
	printf("\nDo you want to delete at any position?(1/0): ");
	scanf("%d",&z);
	if(z==1){
		printf("Enter position: ");
		scanf("%d",&pos);
		if(pos==1){
			temp=head;
			head=head->next;
			free(temp);
		}else{
			struct node *prev=NULL;
			temp=head;
			for(i=1;i<pos && temp!=NULL;i++){
				prev=temp;
				temp=temp->next;
			}
			if(temp==NULL){
				printf("Invalid position!\n");
			}else{
				prev->next=temp->next;
				free(temp);
			}
		}
		printf("After deletion at position %d: ",pos);
		printlist(head);
	}
}

void printlist(struct node *head){
	struct node *temp=head;
	if(head==NULL){
		printf("(empty)\n");
		return;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

