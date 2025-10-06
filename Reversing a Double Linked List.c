#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* list(int n);
void display(struct node *head);

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    struct node *head=list(n);
    printf("\nReversed list: ");
    display(head);
    return 0;
}

struct node* list(int n){
    struct node *head=NULL,*temp,*newnode;
    int i,data;
    for(i=1;i<=n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }

    printf("\nOriginal list: ");
    display(head);

    
    struct node *curr=head,*t=NULL;
    while(curr!=NULL){
        t=curr->prev;
        curr->prev=curr->next;
        curr->next=t;
        curr=curr->prev;
    }
    if(t!=NULL)
        head=t->prev;

    return head;
}

void display(struct node *head){
    struct node *temp=head;
    if(temp==NULL){
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

