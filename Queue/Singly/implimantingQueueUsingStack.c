#include <stdio.h>

#define MAX 10

int stack1[MAX];
int stack2[MAX];
int top1 = -1; 
int top2 = -1;   

void push(int value) {
    if (top1 >= MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        stack1[++top1] = value;
    }
}

int popQueue() {
    if (top2 == -1) {
        if (top1 == -1) {
            printf("Queue Underflow! Queue is empty.\n");
            return -1;
        }

        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }

    return stack2[top2--];
}

int peek(){
    return stack2[top2];
}

int main() {
    // Test the queue
    push(10);
    push(20);
    push(30);

    printf("Dequeued: %d\n", popQueue()); // 10
    printf("Dequeued: %d\n", popQueue()); // 20

    push(40);

    printf("The top element is : %d",peek());

    return 0;
}
