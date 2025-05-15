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

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    
    return head;
}

int main()
{
    struct Node *a = createNode(15);
    a = insertAtEnd(a, 20);
    a = insertAtEnd(a, 25);

    struct Node *temp = a;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}