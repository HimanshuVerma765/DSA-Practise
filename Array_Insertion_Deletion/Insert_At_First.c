#include <stdio.h>
#include <conio.h>

void insertAtStart(int arr[], int *n, int target)
{
    (*n)++;
    for (int i = *n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = target;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 1000;

    insertAtStart(arr, &size, target);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}