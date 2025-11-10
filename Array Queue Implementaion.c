#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

void create(struct Queue *q);
int isFull(struct Queue *q);
int isEmpty(struct Queue *q);
void enqueue(struct Queue *q, int value);
int dequeue(struct Queue *q);
void display(struct Queue *q);

int main() {
    struct Queue q;
    int c, value;

    create(&q);

    while (1) {
        printf("Enter The Operation You Want to perform\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");

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
                if (isFull(&q))
                    printf("Queue is Full.\n");
                else
                    printf("Queue is Not Full.\n");
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

void create(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++(q->rear)] = value;
    printf("%d enqueued into queue.\n", value);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = q->arr[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return value;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    printf("Queue elements are:\n");
    for (i = q->front; i <= q->rear; i++) {
        printf(" %d ", q->arr[i]);
    }
    printf("\n");
}
