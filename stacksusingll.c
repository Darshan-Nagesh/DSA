#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node *next;
}*top;
bool isempty(){
    if(top == NULL){
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
    temp = top;
    printf("\nStack elements: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void push(){
    struct node *newnode = malloc(sizeof(struct node));
    printf("\nEnter the value: "); scanf("%d",&newnode->data);
    newnode->next = top;
    top = newnode;
    display();
}
void pop(){
    struct node *temp;
    if(isempty())
        return;
    temp = top;
    top = top->next;
    printf("\n%d deleted",temp->data);
    free(temp);
    display();
}
void peek(){
    if(isempty())
        return;
    printf("\nTop of stack = %d",top->data);
}
int main(){
    int ch;
    do{
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit");
        printf("\nEnter your choice: "); scanf("%d",&ch);
        switch(ch){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 0: exit(0); break;
            default: printf("\nInvalid choice"); break;
        }
    }while(ch);
    return 0;
}