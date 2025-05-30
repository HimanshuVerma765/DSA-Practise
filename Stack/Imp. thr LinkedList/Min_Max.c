#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Create an empty stack
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Push into stack
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop from stack
int pop(Stack* s) {
    if (s->top == NULL) return INT_MIN;

    Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Peek top element
int peek(Stack* s) {
    return s->top ? s->top->data : INT_MIN;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Free stack
void freeStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}

// Global stacks: main, min, max
Stack* mainStack;
Stack* minStack;
Stack* maxStack;

// Enhanced push
void pushWithMinMax(int data) {
    push(mainStack, data);

    if (isEmpty(minStack) || data <= peek(minStack))
        push(minStack, data);
    else
        push(minStack, peek(minStack));

    if (isEmpty(maxStack) || data >= peek(maxStack))
        push(maxStack, data);
    else
        push(maxStack, peek(maxStack));
}

// Enhanced pop
int popWithMinMax() {
    pop(minStack);
    pop(maxStack);
    return pop(mainStack);
}

// Get min in O(1)
int getMin() {
    return peek(minStack);
}

// Get max in O(1)
int getMax() {
    return peek(maxStack);
}

// Main to test
int main() {
    mainStack = createStack();
    minStack = createStack();
    maxStack = createStack();

    pushWithMinMax(5);
    pushWithMinMax(1);
    pushWithMinMax(10);
    pushWithMinMax(0);

    printf("Current Min: %d\n", getMin()); // 0
    printf("Current Max: %d\n", getMax()); // 10

    popWithMinMax(); // remove 0
    printf("After pop Min: %d\n", getMin()); // 1
    printf("After pop Max: %d\n", getMax()); // 10

    freeStack(mainStack);
    freeStack(minStack);
    freeStack(maxStack);

    return 0;
}