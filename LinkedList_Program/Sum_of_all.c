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

struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

int main()
{
    struct Node *a = createNode(5);
    a = insertAtHead(a, 20);
    a = insertAtHead(a, 10);
    a = insertAtHead(a, 15);
    a = insertAtHead(a, 8);
    a = insertAtHead(a, 12);
    a = insertAtHead(a, 30);
    int sum=0;

    struct Node *temp = a;

    while (temp != NULL)
    {
        printf("%d -> ",temp->data);
        sum+=temp->data;
        temp = temp->next;
    }
    printf("NULL \n");
    printf("The sum of all element is : %d", sum);


    return 0;
}