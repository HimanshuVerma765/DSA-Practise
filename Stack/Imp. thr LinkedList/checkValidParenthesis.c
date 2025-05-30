#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
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
}

struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack *s, char data)
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
        printf("|  %c  |\n", temp->data);
        printf("______\n");
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

int pop(struct Stack *s)
{
    int dlData = s->top->data;
    struct Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return dlData;
}

void checkValidity(char str[])
{
    struct Stack *s = initStack();
    for (int i = 0; i < strlen(str); i++)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')')
        {
            if (!isEmpty(s) && peek(s) == '(')
                pop(s);
            else
                push(s, str[i]);
        }
        else if (str[i] == '}')
        {
            if (!isEmpty(s) && peek(s) == '{')
                pop(s);
            else
                push(s, str[i]);
        }
        else if (str[i] == ']')
        {
            if (!isEmpty(s) && peek(s) == '[')
                pop(s);
            else
                push(s, str[i]);
        }

    }

    if (isEmpty(s))
    {
        printf("String is Valid\n");
    }
    else
    {
        printf("String is not valid\n");
    }
}

int main()
{
    char str[] = "({})}";

    checkValidity(str);

    return 0;
}