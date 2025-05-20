#include <stdio.h>
#include <conio.h>

void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void dutchNationalFlag(int arr[],int size)
{
    int start = 0;
    int mid = 0;
    int end = size - 1;

    while (mid <= end)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr, start, mid);
            mid++;
            start++;
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(arr, mid, end);
            end--;
            break;
        }
    }
}


int main()
{
    int arr[]={0,1,2,0,1,0,2,0,1,0,2,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);

    dutchNationalFlag(arr,size);

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}