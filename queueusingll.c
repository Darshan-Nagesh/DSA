#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next;
}*front, *rear;

bool isempty(){
    if(front == NULL && rear == NULL){
        printf("\nUnderflow");
        return true;
    }
    else
        return false;
}
void display(){
    struct node *temp;
    if(isempty())
        return;
    temp = front;
    printf("\nElements in queue: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void enqueue(){
    struct node *newnode = malloc(sizeof(struct node));
    printf("\nEnter value: "); scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    display();
}
void dequeue(){
    struct node *temp;
    if(isempty())
        return;
    temp = front;
    if(front == rear)
        front = rear = NULL;
    else
        front = front->next;
    printf("%d deleted",temp->data);
    free(temp);
    display();
}
void peek(){
    if(isempty())
        return;
    else
        printf("\nFirst element in queue: %d",front->data);
}
int main(){
    int ch;
    front = rear = NULL;
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
