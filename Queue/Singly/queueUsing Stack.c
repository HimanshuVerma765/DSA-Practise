#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
    struct Node *top;
};

struct Queue{
    struct Stack *input;
    struct Stack *output;
};

struct Stack *initStack()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
};

struct Queue *intiQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->input=NULL;
    q->output=NULL;
    return q;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int main(){

    struct Queue *q = intiQueue();
    return 0;
}