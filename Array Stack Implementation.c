#include <stdio.h>
#include <stdlib.h>

#define MAX 100 


struct Stack {
    int arr[MAX];
    int top;
};

void create(struct Stack *s);
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
void display(struct Stack *s);

int main() {
    struct Stack s;
    int c, value;

    create(&s);

    while (1) {
        printf("Enter The Operation You Want to perform\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
       
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                if (isEmpty(&s))
                    printf("Stack is Empty.\n");
                else
                    printf("Stack is Not Empty.\n");
                break;
            case 5:
                if (isFull(&s))
                    printf("Stack is Full.\n");
                else
                    printf("Stack is Not Full.\n");
                break;
            case 6:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


void create(struct Stack *s) {
    s->top = -1;
    
}

int isFull(struct Stack *s) {
    return (s->top == MAX - 1);
}


int isEmpty(struct Stack *s) {
    return (s->top == -1);
}


void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow");
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed onto stack.\n", value);
}


int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}


void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    int i;
    printf("Stack elements are:\n");
    for (i = s->top; i >= 0; i--) {
        printf(" %d \n", s->arr[i]);
    }
   
}

