#include <stdio.h>
#include <conio.h>

void insertAtLast(int arr[], int *n, int pos)
{
    (*n)--;
    for(int i=pos-1;i<*n;i++){
        arr[i]=arr[i+1];  
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pos = 4;

    insertAtLast(arr, &size,pos);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}