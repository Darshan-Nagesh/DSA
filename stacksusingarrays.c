#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[5];
int top = -1;

int isempty(){
    if (top == -1){
        printf("\nUnderflow");
        return 1;
    }
    else
        return 0;
}
int isfull(){
    if(top == N-1){
        printf("\nOverfllow");
        return 1;
    }
    else
        return 0;
}

void display(){
    int i;
    if (isempty())
        return;
    printf("\nStack elements: ");
    for(i=top; i>=0; i--)
        printf("%d ",stack[i]);
}
void push(){
    int key;
    if(isfull())
        return;
    printf("\nEnter the value: "); scanf("%d",&key);
    top++;
    stack[top] = key;
    display();
}
void pop(){
    if(isempty())
        return;
    printf("\n%d deleted",stack[top]);
    top--;
    display();
}
void peek(){
    if(isempty())
        return;
    printf("\nTop of stack = %d",stack[top]);
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
            case 0 : exit(0); break;
            default: printf("\nInvalid choice"); break;
        }
    }while(ch);
    return 0;
}