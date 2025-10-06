#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addbeg(struct node *head);
void addend(struct node *head);
void pos(struct node *head);
void printlist(struct node *head);

void list(int n){
    struct node *newnode,*head,*temp;
    int data,i;

    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Unable to allocate memory\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    head=newnode;
    temp=newnode;

    for(i=2;i<=n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("Unable to allocate memory\n");
            break;
        }
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }

    printf("\nLinked list elements are: ");
    printlist(head);

    addbeg(head);
    addend(head);
    pos(head);
}

int main(){
    int num;
    printf("Enter the number of elements you want: ");
    scanf("%d",&num);
    list(num);
    return 0;
}

void addbeg(struct node *head){
    struct node *snode;
    int c,data;
    printf("\nDo you want to enter a node at the beginning(1/0):");
    scanf("%d",&c);
    switch(c){
        case 1:
        snode=(struct node*)malloc(sizeof(struct node));
        if(snode==NULL){
            printf("Unable to allocate memory\n");
            break;
        }
        printf("Enter data for node at the beginning:");
        scanf("%d",&data);
        snode->data=data;
        snode->next=head;
        head=snode;
        printf("\nLinked list after insertion at beginning: ");
        printlist(head);
        break;

        case 0: printf("Thanks");
    }
}

void addend(struct node *head){
    struct node *enode,*temp;
    int b,data;
    printf("\nDo you want to add an element at the end?(1/0):");
    scanf("%d",&b);
    switch(b){
        case 1:
        enode=(struct node*)malloc(sizeof(struct node));
        if(enode==NULL){
            printf("Unable to allocate Memory\n");
            break;
        }
        printf("\nEnter data for node at the end: ");
        scanf("%d",&data);
        enode->data=data;
        enode->next=NULL;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=enode;
        printf("\nLinked list after insertion at the end: ");
        printlist(head);
        break;

        case 0: printf("\nThanks");
    }
}

void pos(struct node *head){
    struct node *pnode,*temp;
    int z,pos,data,i;
    printf("\nDo you want to enter an element at any position?(1/0):");
    scanf("%d",&z);
    switch(z){
        case 1:
        printf("\nEnter the position:");
        scanf("%d",&pos);
        if(pos<=0){
            printf("Invalid position!\n");
            break;
        }
        pnode=(struct node*)malloc(sizeof(struct node));
        if(pnode==NULL){
            printf("Unable to allocate memory\n");
            break;
        }
        printf("Enter data: ");
        scanf("%d",&data);
        pnode->data=data;
        pnode->next=NULL;

        if(pos==1){
            pnode->next=head;
            head=pnode;
        }
        else{
            temp=head;
            for(i=1;i<pos-1 && temp!=NULL;i++){
                temp=temp->next;
            }
            if(temp==NULL){
                printf("Position out of range\n");
                free(pnode);
                break;
            }
            pnode->next=temp->next;
            temp->next=pnode;
        }
        printf("\nLinked list after insertion at position %d: ",pos);
        printlist(head);
        break;

        case 0: printf("\nThanks");
    }
}

void printlist(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

