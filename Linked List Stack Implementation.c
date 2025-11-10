#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void create(struct Stack *s);
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
        printf("5. Exit\n");

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
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void create(struct Stack *s) {
    s->top = NULL;
}

int isEmpty(struct Stack *s) {
    return (s->top == NULL);
}

void push(struct Stack *s, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushed onto stack.\n", value);
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node *temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = s->top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf(" %d \n", temp->data);
        temp = temp->next;
    }
}

