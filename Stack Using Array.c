#include<stdio.h>
#include<stdlib.h>
#define MAXX 200
struct lifo {
   int arr[MAXX];
   int top;
};

typedef struct lifo stack;

void create(stack *s){
     s->top=-1;
}

int isFull(stack *s){
     return (s->top==MAXX-1);
}

int isEmpty(stack *s){
   return (s->top==-1);
}

void push(stack *s,int x){

     if(isFull(s)){
          printf("Stack Overflow\n");
          return;
     }

     s->top++;
     s->arr[s->top]=x;

     if(isFull(s))
          printf("Stack is Full\n");
}

int pop(stack *s){

     if(isEmpty(s)){
          printf("Stack Underflow\n");
          return -1;
     }

     int y=s->arr[s->top];
     s->top--;

     if(isEmpty(s))
          printf("Warning: Stack is Empty\n");

     return y;
}

void display(stack *s){
	int i;

     if(isEmpty(s)){
          printf("Stack is empty\n");
          return;
     }
    printf("\nElements in Stack: ");
     for(i=s->top;i>=0;i--)
          printf("%d ",s->arr[i]);

     printf("\n");
}

int main(){

     stack s;
     create(&s);

     int x,c;

     while(1){

          printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice: ");
          scanf("%d",&c);

          switch(c){

               case 1:
                    printf("Enter element: ");
                    scanf("%d",&x);
                    push(&s,x);
                    break;

               case 2:
                    x=pop(&s);
                    if(x!=-1)
                         printf("%d\n",x);
                    break;

               case 3:
                    display(&s);
                    break;

               case 4:
                    exit(0);

               default:
                    printf("Invalid choice\n");
          }
     }

     return 0;
}

