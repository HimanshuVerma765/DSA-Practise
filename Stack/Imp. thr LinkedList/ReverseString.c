#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

struct Stack *initStack() {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
}

struct Node *createNode(char data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack *s, char data) {
    struct Node *newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

char peek(struct Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->top->data;
}

int isEmpty(struct Stack *s) {
    return (s->top == NULL);
}

char pop(struct Stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow.\n");
        return '\0';
    }
    char dlData = s->top->data;
    printf("%c ", dlData);
    struct Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return dlData;
}

void printStack(struct Stack *s) {
    struct Node *temp = s->top;
    while (temp != NULL) {
        printf("|  %c  |\n", temp->data);
        printf("-------\n");
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseString(struct Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

int main() {
    struct Stack *s = initStack();
    push(s, 'A');
    push(s, 'B');
    push(s, 'C');
    push(s, 'D');
    push(s, 'E');

    printf("\nOriginal Stack:\n");
    printStack(s);

    printf("\nReversed Stack:\n");
    reverseString(s);

    return 0;
}
