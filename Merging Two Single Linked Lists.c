#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
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

    
    struct node *i,*j;
    int temp;
    for(i=head1;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

    
    for(i=head2;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

   
    struct node *merged=NULL,*temp1=head1,*temp2=head2,*t=NULL;

    if(temp1==NULL) merged=temp2;
    else if(temp2==NULL) merged=temp1;
    else{
        if(temp1->data <= temp2->data){
            merged=temp1;
            temp1=temp1->next;
        }else{
            merged=temp2;
            temp2=temp2->next;
        }
        t=merged;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data <= temp2->data){
                t->next=temp1;
                t=t->next;
                temp1=temp1->next;
            }else{
                t->next=temp2;
                t=t->next;
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL) t->next=temp1;
        if(temp2!=NULL) t->next=temp2;
    }

    printf("\nMerged sorted list: ");
    display(merged);

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
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
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

