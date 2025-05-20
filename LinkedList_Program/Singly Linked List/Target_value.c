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
    a = insertAtEnd(a, 60);
    a = insertAtEnd(a, 40);
    a = insertAtEnd(a, 45);
    a = insertAtEnd(a, 50);
    a = insertAtEnd(a, 30);
    a = insertAtEnd(a, 60);

    struct Node *temp1 = a;
    int target = 90;


    while (temp1 != NULL)
    {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL");


    temp1 = a;


    while(temp1 != NULL){
        struct Node *temp2 = temp1->next;
        while (temp2!= NULL)
        {
            if(temp1->data+temp2->data==target){
                printf("\nThe pair is : %d %d", temp1->data, temp2->data);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }


    return 0;
}