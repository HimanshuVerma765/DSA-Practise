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
}

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

void printStack(struct Stack *s)
{
    struct Node *temp = s->top;

    while (temp != NULL)
    {
        printf("|  %d  |\n", temp->data);
        printf("-------\n");
        temp = temp->next;
    }
    printf("NULL\n");
}

int peek(struct Stack *s)
{
    return s->top->data;
}

int isEmpty(struct Stack *s)
{
    return (s->top == NULL);
}

int pop(struct Stack *s){
    int dlData = s->top->data;
    struct Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return dlData;
}

void main(){
    struct Stack *s = initStack();
    push(s,40);
    push(s,80);
    push(s,16);
    push(s,20);
    push(s,24);

    if(isEmpty(s)){
        printf("Stack is empty");
    }
    else{
        printf("Top element is %d",peek(s));
    }

    printf("\n");
    printStack(s);
    printf("Deleted element is %d",pop(s));
    printf("\n");
    printStack(s);
}