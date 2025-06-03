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
        printf("  %d  \n", temp->data);
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

struct Stack *sortUsingAnotherStack(struct Stack *s1, struct Stack *s2)
{
    while (!isEmpty(s1)) //1
    {
        int tmp = pop(s1);  //temp=4

        while (!isEmpty(s2) && peek(s2) > tmp) 
        {
            push(s1, pop(s2));
        }
        push(s2, tmp);
    }

    return s2;
}



int main(){
    struct Stack *s1 = initStack();
    struct Stack *s2 = initStack();
    push(s1,1);
    push(s1,10);
    push(s1,7);
    push(s1,3);

    printStack(s1);
    sortUsingAnotherStack(s1,s2);
    printStack(s2);

    return 0;
}