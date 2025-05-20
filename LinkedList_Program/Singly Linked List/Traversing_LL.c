#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    struct Node *a = createNode(15);
    struct Node *b = createNode(20);
    struct Node *c = createNode(25);
    struct Node *d = createNode(30);
    struct Node *e = createNode(35);
    struct Node *f = createNode(40);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    struct Node *temp = a;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}