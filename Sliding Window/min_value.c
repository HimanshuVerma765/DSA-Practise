#include<stdio.h>
#include<conio.h>

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int window=0;
    int min=1000;


    for (int i = 0; i < k; i++)
    {
        window += arr[i];
    }


    for(int i = k; i < n; i++)
    {
        if(window < min)
        {
            min = window;
        }

        window = window - arr[i - k] + arr[i];
    };
    
    printf("Minimum sum of the window is %d\n", min);

    return 0;
}