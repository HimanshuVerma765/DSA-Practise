#include<stdio.h>
#include<conio.h>

void shiftZeroOne(int arr[],int size){
    int i=0,j=0;

    while(j<size){
        if(arr[j]==0){
            arr[i]=arr[j];
            i++;
        }
        j++;
    }

    while(i<size){
        arr[i]=1;
        i++;
    }
}
 
int main()
{
 int arr[]={0,1,0,1,0,1,0,1,0};
 int size = sizeof(arr)/sizeof(arr[0]);

 shiftZeroOne(arr,size);

 for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
 }

 
return 0;
}