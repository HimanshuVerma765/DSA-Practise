#include<stdio.h>
#include<conio.h>
 
int main()
{
 int a=10;
 int* b=&a;

 printf("\nThe value of a is : %d",a);
 printf("\nThe value of a is : %d",*b);
 
return 0;
}