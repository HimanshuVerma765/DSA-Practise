#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
};

// Initialize deque
struct Deque *initDeque() {
    struct Deque *dq = (struct Deque *)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Push at rear
void pushRear(struct Deque *dq, int data) {
    struct Node *newNode = createNode(data);
    if (dq->rear == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        newNode->prev = dq->rear;
        dq->rear = newNode;
    }
}

// Push at front
void pushFront(struct Deque *dq, int data) {
    struct Node *newNode = createNode(data);
    if (dq->front == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

// Pop from front
int popFront(struct Deque *dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
        return -1;
    }
    int val = dq->front->data;
    struct Node *temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;
    free(temp);
    return val;
}

// Pop from rear
int popRear(struct Deque *dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty.\n");
        return -1;
    }
    int val = dq->rear->data;
    struct Node *temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear)
        dq->rear->next = NULL;
    else
        dq->front = NULL;
    free(temp);
    return val;
}

// Check if empty
int isEmpty(struct Deque *dq) {
    return dq->front == NULL;
}

// Print deque
void printDeque(struct Deque *dq) {
    struct Node *temp = dq->front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
void main() {
    struct Deque *dq = initDeque();

    pushRear(dq, 10);
    pushRear(dq, 20);
    pushFront(dq, 5);
    pushFront(dq, 2);

    printDeque(dq);

    printf("Pop Front: %d\n", popFront(dq));
    printf("Pop Rear: %d\n", popRear(dq));

    printDeque(dq);

    printf("Is Deque Empty? %s\n", isEmpty(dq) ? "Yes" : "No");

    popFront(dq);
    popFront(dq);
    printDeque(dq);
    printf("Is Deque Empty? %s\n", isEmpty(dq) ? "Yes" : "No");
}
