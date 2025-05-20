#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node *deleteAtEnd(struct Node *head){
    struct Node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
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
    newNode->prev=temp;
    
    return head;
}

int main()
{
    struct Node *a = createNode(15);
    a = insertAtEnd(a, 20);
    a = insertAtEnd(a, 25);

    struct Node *temp = a;

    printf("NULL");
    while (temp != NULL)
    {
        printf("<- %d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

deleteAtEnd(a);

temp=a;

    printf("\nNULL");
    while (temp != NULL)
    {
        printf("<- %d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");


    return 0;
}