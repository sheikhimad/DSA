#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
void addbeg(struct node *head);
void addend(struct node *head);
void addpos(struct node *head);

void list(){
    struct node *head=NULL,*temp,*newnode;
    int n,i,pos,ch,data;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            newnode->next=head;
        }else{
            temp=head;
            while(temp->next!=head)
			 temp=temp->next;
            temp->next=newnode;
            newnode->next=head;
        }
    }

    printf("\nOriginal List: ");
    display(head);

    printf("\nDo you want to add a node at beginning? (1/0): ");
    scanf("%d",&ch);
    if(ch==1){
        addbeg(head);
        display(head);
    }

    printf("\nDo you want to add a node at end? (1/0): ");
    scanf("%d",&ch);
    if(ch==1){
        addend(head);
        display(head);
    }

    printf("\nDo you want to add a node at any position? (1/0): ");
    scanf("%d",&ch);
    if(ch==1){
        addpos(head);
        display(head);
    }
}

int main(){
    list();
    return 0;
}

void display(struct node *head){
    if(head==NULL){printf("List empty\n"); return;}
    struct node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

void addbeg(struct node *head){
    struct node *temp=head,*newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for new node at beginning: ");
    scanf("%d",&newnode->data);
    while(temp->next!=head) 
	temp=temp->next;
    newnode->next=head;
    temp->next=newnode;
}

void addend(struct node *head){
    struct node *temp=head,*newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for new node at end: ");
    scanf("%d",&newnode->data);
    while(temp->next!=head) 
	temp=temp->next;
    temp->next=newnode;
    newnode->next=head;
}

void addpos(struct node *head){
    struct node *temp=head,*newnode=(struct node*)malloc(sizeof(struct node));
    int pos,i;
    printf("Enter position to insert: ");
    scanf("%d",&pos);
    printf("Enter data for new node: ");
    scanf("%d",&newnode->data);
    for(i=1;i<pos-1 && temp->next!=head;i++) 
	temp=temp->next;
    newnode->next=temp->next;
    temp->next=newnode;
}

