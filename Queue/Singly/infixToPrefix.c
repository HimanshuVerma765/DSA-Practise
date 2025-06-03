#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
    char data; // changed from int to char for operator/operand handling
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
    newNode->next = s->top;
    s->top = newNode;
}

char peek(struct Stack *s)
{
    if (s->top)
        return s->top->data;
    return '\0';
}

int isEmpty(struct Stack *s)
{
    return (s->top == NULL);
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
        return '\0';
    char popped = s->top->data;
    struct Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return popped;
}

int precedence(char value)
{
    if (value == '+' || value == '-')
        return 1;
    else if (value == '*' || value == '/')
        return 2;
    else if (value == '^')
        return 3;
    else
        return 0;
}

// Reverse string function (since strrev is not standard in all compilers)
void reverseString(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main()
{
    struct Stack *s = initStack();
    char str[] = "a+b*c";
    reverseString(str); // replace strrev with custom reverse

    char str2[100]; // buffer to hold the output
    int j = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i]))
        {
            str2[j++] = str[i];
        }
        else
        {
            while (!isEmpty(s) && precedence(str[i]) < precedence(peek(s)))
            {
                str2[j++] = pop(s);
            }
            push(s, str[i]);
        }
    }

    while (!isEmpty(s))
    {
        str2[j++] = pop(s);
    }

    str2[j] = '\0'; // null terminate the string

    reverseString(str2); // reverse back to get prefix
    printf("Prefix Expression: %s\n", str2);

    return 0;
}
