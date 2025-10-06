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
    int n1,n2;
    printf("Enter number of nodes for first list: ");
    scanf("%d",&n1);
    struct node *head1=list(n1);

    printf("Enter number of nodes for second list: ");
    scanf("%d",&n2);
    struct node *head2=list(n2);

    
    struct node *temp=head1;
    if(temp!=NULL){
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=head2;
        if(head2!=NULL)
            head2->prev=temp;
    }else{
        head1=head2;
    }

    printf("\nConcatenated list: ");
    display(head1);

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
    printf("List created: ");
    display(head);
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

