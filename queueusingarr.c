#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define N 5

int arr[N];
int front, rear;

bool isempty(){
    if(front == -1 && rear == -1){
        printf("\nUnderflow");
        return true;
    }
    else
        return false;
}
bool isfull(){
    if(rear == N-1){
        printf("\nOverflow");
        return true;
    }
    else
        return false;
}
void display(){
    int i;
    if(isempty())
        return;
    printf("\nElements in queue: ");
    for(i=front;i<=rear;i++)
        printf("%d ",arr[i]);
}
void enqueue(){
    int key;
    if(isfull())
        return;
    printf("\nEnter value: "); scanf("%d",&key);
    if(front == -1 && rear == -1){
        front = rear = 0;
        arr[rear] = key;
    }
    else{
        rear++;
        arr[rear] = key;
    }
    display();
}
void dequeue(){
    if(isempty())
        return;
    if(front == rear){
        printf("\n%d deleted",arr[front]);
        front = rear = -1;
    }
    else{
        printf("\n%d deleted",arr[front]);
        front++;
    }
    display();
}
void peek(){
    if(isempty())
        return;
    else
        printf("\nFirst element in queue: %d",arr[front]);
}
int main(){
    int ch;
    front = rear = -1;
    do{
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Dsiplay\n0. Exit\nEnter your choice: ");
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