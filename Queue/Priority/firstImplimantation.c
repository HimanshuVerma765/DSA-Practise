#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};

// Create a new node
struct Node *createNode(int data, int priority) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Push node into priority queue (lower number = higher priority)
struct Node* push(struct Node *head, int data, int priority) {
    struct Node *newNode = createNode(data, priority);

    // Insert at beginning if head is NULL or has lower priority
    if (head == NULL || priority < head->priority) {
        newNode->next = head;
        return newNode;
    }

    // Traverse to find the correct position
    struct Node *current = head;
    while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Pop the highest priority element
struct Node* pop(struct Node *head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
    return head;
}

// Peek at the highest priority element
int peek(struct Node *head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    return head->data;
}

// Check if the queue is empty
int isEmpty(struct Node *head) {
    return head == NULL;
}

// Print the queue
void printQueue(struct Node *head) {
    struct Node *temp = head;
    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("(%d, p=%d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
void main() {
    struct Node *head = NULL;

    head = push(head, 30, 3);
    head = push(head, 10, 1);
    head = push(head, 20, 2);
    head = push(head, 40, 0);

    printQueue(head);

    printf("Peek: %d\n", peek(head));

    head = pop(head);
    head = pop(head);

    printQueue(head);

    printf("Is Queue Empty? %s\n", isEmpty(head) ? "Yes" : "No");

    head = pop(head);
    head = pop(head);

    printQueue(head);
    printf("Is Queue Empty? %s\n", isEmpty(head) ? "Yes" : "No");
}