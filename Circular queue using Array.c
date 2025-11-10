#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct CircularQueue {
    int arr[MAX];
    int front, rear;
};

void create(struct CircularQueue *q);
int isFull(struct CircularQueue *q);
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

void create(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("%d enqueued into queue.\n", value);
}

int dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;
    return value;
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    printf("Queue elements are:\n");
    while (1) {
        printf(" %d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

