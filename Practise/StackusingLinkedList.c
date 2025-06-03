#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Stack *initStack()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void push(struct Stack *s, int data)
{
    struct Node *newNode = createNode(data);
    if (s->top == NULL)
    {
        s->top = newNode;
        return;
    }
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack *s)
{
    int dlData = s->top->data;
    struct Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return dlData;
}

void printStack(struct Stack *s)
{
    struct Node *temp = s->top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

int peek(struct Stack *s)
{
    return s->top->data;
}

int isEmpty(struct Stack *s)
{
    return s->top == NULL;
}

void main()
{
    struct Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    push(s, 70);
    push(s, 80);
    printStack(s);
}