#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 5

int arr[5], front, rear;

bool isfull(){
    if((rear+1)%N == front){
        printf("\nOverflow");
        return true;
    }
    else
        return false;
}
bool isempty(){
    if(front == -1 && rear == -1){
        printf("\nUnderflow");
        return true;
    }
    else
        return false;
}
void display(){
    int i;
    i = front;
    printf("\nElements in queue: ");
    while(i!=rear){
        printf("%d ",arr[i]);
        i = (i+1)%N;
    }
    printf("%d",arr[rear]);
}
void enqueue(){
    int key;
    if(isfull())
        return;
    printf("\nEnter the value: "); scanf("%d",&key);
    if(front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = (rear+1)%N;
    arr[rear] = key;
    display();
}
void dequeue(){
    if(isempty())
        return;
    printf("\n%d deleted",arr[front]);
    if(front == rear)
        front = rear = -1;
    else
        front = (front+1)%N;
    display();
}
void peek(){
    if(isempty())
        return;
    printf("\nFirst element in queue: %d",arr[front]);
}
int main(){
    int ch;
    front = rear = -1;
    do{
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n0. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 0: exit(0); break;
            default: printf("\nInvalid choice"); break;
        }
    }while(ch);
    return 0;
}