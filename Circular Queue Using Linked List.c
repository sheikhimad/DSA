#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct CircularQueue {
    struct Node *front, *rear;
};

void create(struct CircularQueue *q);
int isEmpty(struct CircularQueue *q);
void enqueue(struct CircularQueue *q, int value);
int dequeue(struct CircularQueue *q);
void display(struct CircularQueue *q);

int main() {
    struct CircularQueue q;
    int c, value;

    create(&q);

    while (1) {
        printf("Enter The Operation You Want to perform\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued element: %d\n", value);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                if (isEmpty(&q))
                    printf("Queue is Empty.\n");
                else
                    printf("Queue is Not Empty.\n");
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

void create(struct CircularQueue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct CircularQueue *q) {
    return (q->front == NULL);
}

void enqueue(struct CircularQueue *q, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    if (q->front == NULL) {
        q->front = q->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued into queue.\n", value);
}

int dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value;
    struct Node *temp = q->front;
    if (q->front == q->rear) {
        value = temp->data;
        q->front = q->rear = NULL;
    } else {
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    free(temp);
    return value;
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = q->front;
    printf("Queue elements are:\n");
    do {
        printf(" %d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

