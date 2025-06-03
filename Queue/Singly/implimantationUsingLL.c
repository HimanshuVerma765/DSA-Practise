#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rare;
};

struct Queue *initQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rare = NULL;
    return q;
}

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue *q, int data) {
    struct Node *newNode = createNode(data);
    if (q->rare == NULL) {
        q->front = q->rare = newNode;
    } else {
        q->rare->next = newNode;
        q->rare = newNode;
    }
}

void printQueue(struct Queue *q) {
    struct Node *temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

int dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot pop.\n");
        return -1;
    }
    int value = q->front->data;
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rare = NULL;
    free(temp);
    return value;
}

void main() {
    struct Queue *q = initQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    printf("Peek: %d\n", peek(q));
    printf("Pop: %d\n", dequeue(q));
    printQueue(q);

    printf("Is Queue Empty? %s\n", isEmpty(q) ? "Yes" : "No");

    dequeue(q);
    dequeue(q);
    printQueue(q);
    printf("Is Queue Empty? %s\n", isEmpty(q) ? "Yes" : "No");
}