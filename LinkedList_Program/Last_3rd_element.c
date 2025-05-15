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

    struct Node *temp = a;

    while (temp != NULL)
    {
        if (temp->next->next->next==NULL)
        {
            printf("The Last 3rd element is : %d", temp->data);
            break;
        }
        temp = temp->next;
    }

    return 0;
}