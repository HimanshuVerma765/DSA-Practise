#include <stdio.h>
#include <conio.h>

void insertAtLast(int arr[], int *n, int target)
{
    (*n)++;
    arr[*n-1] = target;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 1000;

    insertAtLast(arr, &size, target);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}