#include <stdio.h>
#include <conio.h>

void insertAtPosition(int arr[], int *size, int pos, int value)
{
    (*size)++;

    for (int i = *size - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertAtPosition(arr, &size, 4, 1000);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}