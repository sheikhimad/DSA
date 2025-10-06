#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void list(int n);
void printlist(struct node *head);
void delbeg(struct node *head);
void delend(struct node *head);
void delpos(struct node *head);

int main() {
    int n;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    list(n);
    return 0;
}

void list(int n) {
    int data,i;
    struct node *newnode,*head,*temp;
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

    delbeg(head);
    delend(head);
    delpos(head);
}

void delbeg(struct node *head){
    struct node *temp;
    int c;
    printf("\nDo you want to delete the node at the beginning? (1/0): ");
    scanf("%d",&c);
    if(c==1){
        if(head==NULL){
            printf("List is empty.\n");
            return;
        }
        temp=head;
        head=temp->next;
        if(head!=NULL)
            head->prev=NULL;
        free(temp);
        printf("Linked List after deletion at beginning:\n");
        printlist(head);
    }else{
        printf("No deletion at beginning.\n");
    }
}

void delend(struct node *head){
    struct node *temp;
    int c;
    printf("\nDo you want to delete the node at the end? (1/0): ");
    scanf("%d",&c);
    if(c==1){
        if(head==NULL){
            printf("List is empty.\n");
            return;
        }
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        if(temp->prev!=NULL)
            temp->prev->next=NULL;
        else
            head=NULL;
        free(temp);
        printf("Linked List after deletion at end:\n");
        printlist(head);
    }else{
        printf("No deletion at end.\n");
    }
}

void delpos(struct node *head){
    struct node *temp;
    int x,pos,i;
    printf("\nDo you want to delete a node at any position? (1/0): ");
    scanf("%d",&x);
    if(x==1){
        printf("Enter position to delete: ");
        scanf("%d",&pos);
        if(pos<1){
            printf("Invalid position.\n");
            return;
        }
        temp=head;
        if(pos==1){
            head=temp->next;
            if(head!=NULL)
                head->prev=NULL;
            free(temp);
        }else{
            for(i=1;i<pos;i++)
                temp=temp->next;
            if(temp==NULL){
                printf("Position out of range.\n");
                return;
            }
            temp->prev->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=temp->prev;
            free(temp);
        }
        printf("Linked List after deletion at position %d:\n",pos);
        printlist(head);
    }else{
        printf("No deletion at any position.\n");
    }
}

void printlist(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

