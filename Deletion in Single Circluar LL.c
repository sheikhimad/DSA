#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
void delbeg(struct node *head);
void delend(struct node *head);
void delpos(struct node *head);

void list(){
    struct node *head=NULL,*temp,*newnode;
    int n,i,ch,pos;

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
            while(temp->next!=head) temp=temp->next;
            temp->next=newnode;
            newnode->next=head;
        }
    }

    printf("\nOriginal List: ");
    display(head);

    printf("\nDo you want to delete node at beginning? (1/0): ");
    scanf("%d",&ch);
    if(ch==1){ delbeg(head); display(head); }

    printf("\nDo you want to delete node at end? (1/0): ");
    scanf("%d",&ch);
    if(ch==1){ delend(head); display(head); }

    printf("\nDo you want to delete node at any position? (1/0): ");
    scanf("%d",&ch);
    if(ch==1){ delpos(head); display(head); }
}

int main(){
    list();
    return 0;
}

void display(struct node *head){
    if(head==NULL){ printf("List empty\n"); return; }
    struct node *temp=head;
    do{ printf("%d ",temp->data); temp=temp->next; }while(temp!=head);
    printf("\n");
}

void delbeg(struct node *head){
    if(head==NULL) return;
    struct node *temp=head;
    while(temp->next!=head) temp=temp->next;
    struct node *del=head;
    if(head->next==head){ free(del); head=NULL; return; }
    temp->next=head->next;
    head=head->next;
    free(del);
}

void delend(struct node *head){
    if(head==NULL) return;
    struct node *temp=head,*prev=NULL;
    if(temp->next==head){ free(temp); head=NULL; return; }
    while(temp->next!=head){ prev=temp; temp=temp->next; }
    prev->next=head;
    free(temp);
}

void delpos(struct node *head){
    int pos,i;
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    if(pos==1){ delbeg(head); return; }
    struct node *temp=head;
    for(i=1;i<pos-1 && temp->next!=head;i++) 
	temp=temp->next;
    struct node *del=temp->next;
    temp->next=del->next;
    free(del);
}

