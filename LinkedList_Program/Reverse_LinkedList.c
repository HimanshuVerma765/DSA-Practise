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
    a = insertAtEnd(a, 30);
    a = insertAtEnd(a, 35);
    a = insertAtEnd(a, 40);
    a = insertAtEnd(a, 45);
    a = insertAtEnd(a, 50);
    a = insertAtEnd(a, 55);
    a = insertAtEnd(a, 60);

    struct Node *temp = a;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    struct Node *prev = NULL;
    struct Node *current = a;
    struct Node *next = a->next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
printf("\n");
    while (prev != NULL)
    {
        printf("%d -> ", prev->data);
        prev = prev->next;
    }
    printf("NULL");
    

    return 0;
}